#ifndef DEDSERV

#include "sfx.h"
#include "gconsole.h"
#include "base_object.h"
#include "util/macros.h"
#include <boost/assign/list_inserter.hpp>
using namespace boost::assign;

#include <vector>
#include <list>
#ifdef __MINGW32__ //Fixes issue on using proper calling convention on FMODEx while using mingw (for some reason)
	#define __CYGWIN32__
#endif
#include <fmod.hpp>
#ifdef __MINGW32__
	#undef __CYGWIN32__
#endif
#include <fmod_errors.h>
#include <boost/utility.hpp>

#define FMOD_ERROR_CHECK \
	if (fmod_result != FMOD_OK) { \
		console.addLogMsg(std::string("* FMOD ERROR ") + FMOD_ErrorString(fmod_result)); \
		return; \
	}
// cerr << "* FMOD ERROR " << FMOD_ErrorString(sfx.fmod_result) << endl;

Sfx sfx;

namespace
{
	bool m_initialized = false;
	
	std::list< std::pair< FMOD::Channel*, BaseObject* > > chanObject;
	std::vector<Listener*> listeners;
	
	float m_volume = 1.0;
	float m_listenerDistance = 1.0;
}

void volume( float oldValue )
{
	if (sfx) sfx.volumeChange();
}

Sfx::Sfx()
{
}

Sfx::~Sfx()
{
}

void Sfx::init()
{
	// Select a driver
	fmod_result = FMOD::System_Create(&m_fmod_system);		// Create the main system object.
	FMOD_ERROR_CHECK;

	fmod_result = m_fmod_system->setOutput(m_outputMode);
	FMOD_ERROR_CHECK;
	
	fmod_result = m_fmod_system->setDriver(0);
	FMOD_ERROR_CHECK;
	
	fmod_result = m_fmod_system->init(32, FMOD_INIT_NORMAL, 0);	// Initialize FMOD.
	FMOD_ERROR_CHECK;
	//fmod already sets software sample rate to 48000.
	

	/* We select default driver for now
	int numDrivers = FSOUND_GetNumDrivers();
	// TODO: Desired driver here: std::string desiredDriver(); 
	int selectedDriver = 0;
	
	for(int i = 0; i < numDrivers; ++i)
	{
		const char* driverName = FSOUND_GetDriverName(i);
		console.addLogMsg(std::string("* FMOD DRIVER ") + cast<std::string>(i) + std::string(": ") + driverName);
		if(std::string(driverName).find(desiredDriver) >= 0)
		{
			selectedDriver = i;
			break;
		}
	}
	
	FSOUND_SetDriver(selectedDriver);*/
	
	fmod_result = m_fmod_system->set3DSettings(1.0, 20.0, 2.0);
	FMOD_ERROR_CHECK;

	fmod_result = m_fmod_system->getMasterChannelGroup(&m_fmod_mastercg);
	FMOD_ERROR_CHECK;
	
	volumeChange();
	
	int fmod_driver_number;
	char* fmod_driver_name = (char*)malloc(64+1);
	fmod_result = m_fmod_system->getDriver(&fmod_driver_number);
	FMOD_ERROR_CHECK;
	fmod_result = m_fmod_system->getDriverInfo(fmod_driver_number, fmod_driver_name, 64+1, 0);
	FMOD_ERROR_CHECK;
	
	console.addLogMsg(std::string("* FMOD LIB INITIALIZED, USING DRIVER ") + fmod_driver_name);
	m_initialized = true;
}

void Sfx::shutDown()
{
	fmod_result = m_fmod_system->release();
	FMOD_ERROR_CHECK;
	m_fmod_system = nullptr;
}

void Sfx::registerInConsole()
{
	{
		EnumVariable::MapType outputModes;
		insert(outputModes)
			("AUTO", FMOD_OUTPUTTYPE_AUTODETECT)
			("NOSFX", FMOD_OUTPUTTYPE_NOSOUND)
#ifdef WINDOWS
			("DSOUND", FMOD_OUTPUTTYPE_DSOUND) //Default on older Windows
			("WINMM", FMOD_OUTPUTTYPE_WINMM)
			("WASAPI", FMOD_OUTPUTTYPE_WASAPI) //Default on Windows Vista and above
			("ASIO", FMOD_OUTPUTTYPE_ASIO) //Low latency
#else //ifdef LINUX
			("ALSA", FMOD_OUTPUTTYPE_ALSA) //Default on Linux
			("PULSEAUDIO", FMOD_OUTPUTTYPE_PULSEAUDIO)
			("OSS", FMOD_OUTPUTTYPE_OSS)
			("ESD", FMOD_OUTPUTTYPE_ESD)
			("COREAUDIO", FMOD_OUTPUTTYPE_COREAUDIO) //Mac ONLY - but might work under Wine there!
#endif
		;

		console.registerVariables()
			("SFX_VOLUME", &m_volume, 1.0, volume)
			("SFX_LISTENER_DISTANCE", &m_listenerDistance, 20)
			(new EnumVariable("SFX_OUTPUT_MODE", (int*)&m_outputMode, FMOD_OUTPUTTYPE_AUTODETECT, outputModes))
		;
		
		// NOTE: When/if adding a callback to sfx variables, make it do nothing if
		// sfx.operator bool() returns false.
	}
}

void Sfx::think()
{
	fmod_result = m_fmod_system->update();
	FMOD_ERROR_CHECK;
	
	for (size_t i = 0; i < listeners.size(); ++i )
	{
		fmod_result = m_fmod_system->set3DNumListeners(listeners.size());
		FMOD_ERROR_CHECK;
		FMOD_VECTOR pos[3] = { listeners[i]->pos.x, listeners[i]->pos.y, -m_listenerDistance };
		FMOD_VECTOR forward[3] = { 0.0f, 0.0f, 1.0f };
		FMOD_VECTOR up[3] = { 0.0f, 1.0f, 0.0f };
		fmod_result = m_fmod_system->set3DListenerAttributes(i, pos, 0, forward, up);
		FMOD_ERROR_CHECK;
	}
	
	//Update 3d channel that follow objects positions
	/*
	std::list< std::pair< int, BaseObject* > >::iterator obj, next;
	for ( obj = chanObject.begin(); obj != chanObject.end(); obj = next)
	{
		next = boost::next(obj);

	*/
	foreach_delete(obj, chanObject)
	{
		bool fmod_channel_isPlaying;
		fmod_result = ( obj->first )->isPlaying(&fmod_channel_isPlaying);
		FMOD_ERROR_CHECK;
		
		if( !obj->second
		||  obj->second->deleteMe
		||  !fmod_channel_isPlaying )
		{
			chanObject.erase(obj);
		}
		else
		{
			FMOD_VECTOR pos[3] = { obj->second->pos.x, obj->second->pos.y, 0 };
			fmod_result = (obj->first)->set3DAttributes(pos, 0);
			FMOD_ERROR_CHECK;
		}
	}

/*
	//Check for deleted objects
	for ( obj = chanObject.begin(); obj != chanObject.end(); )
	{
		if ( obj->second && ( obj->second->deleteMe || !FSOUND_IsPlaying( obj->first ) ) )
		{
			std::list< std::pair< int, BaseObject* > >::iterator tmp = obj;
			obj++;
			chanObject.erase(tmp);
		}
		else
			obj++;
	}*/

}

void Sfx::setChanObject(FMOD::Channel* chan, BaseObject* object)
{
	chanObject.push_back( std::pair< FMOD::Channel*, BaseObject* > ( chan, object ) );
}
	
void Sfx::clear()
{
	chanObject.clear();
}

Listener* Sfx::newListener()
{
	listeners.push_back( new Listener );
	return listeners.back();
}

void Sfx::freeListener(Listener* listener)
{
	std::vector<Listener*>::iterator i;
	for ( i = listeners.begin(); i != listeners.end(); ++i )
	{
		if ( listener == *i )
		{
			delete *i;
			listeners.erase(i);
			break;
		}
	}
}

void Sfx::volumeChange()
{
	fmod_result = m_fmod_mastercg->setVolume(m_volume);	// Initialize FMOD.
	FMOD_ERROR_CHECK;
}

Sfx::operator bool()
{
	return m_initialized;
} 

#endif
