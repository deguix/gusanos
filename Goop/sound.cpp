#ifndef DEDSERV

#include "sound.h"

#include "sfx.h"
#include "resource_list.h"
#include "util/math_func.h"
#include "base_object.h"

#include <string>
#include <iostream>
#include <boost/filesystem/path.hpp>
namespace fs = boost::filesystem;

#include <allegro.h>
//#include "text.h"

#include <fmod.hpp>
#include <fmod_errors.h>

using namespace std;

//		console.addLogMsg(string("* FMOD ERROR ") + FMOD_ErrorString(fmod_result));

#define FMOD_ERROR_CHECK \
	if (sfx.fmod_result != FMOD_OK) { \
		cerr << "* FMOD ERROR " << FMOD_ErrorString(sfx.fmod_result) << endl; \
		return; \
	}
#define FMOD_ERROR_CHECK_WITH_BOOLEAN \
	if (sfx.fmod_result != FMOD_OK) { \
		cerr << "* FMOD ERROR " << FMOD_ErrorString(sfx.fmod_result) << endl; \
		return false; \
	}

ResourceList<Sound> soundList;

Sound::Sound()
{
	m_sound = nullptr;
}

Sound::~Sound()
{
	if (m_sound) {
		sfx.fmod_result = m_sound->release();
		FMOD_ERROR_CHECK;
	}
}

bool Sound::load(fs::path const& filename)
{	
	//cerr << "Loading sound: " << filename.native() << endl;
	sfx.fmod_result = sfx.m_fmod_system->createSound(filename.native().c_str(), FMOD_3D | FMOD_HARDWARE, 0, &m_sound); //FSOUND_FORCEMONO
	FMOD_ERROR_CHECK_WITH_BOOLEAN;
	if ( m_sound )
	{
		return true;
	}
	return false;
}

void Sound::play(float volume,float pitch, float volumeVariation, float pitchVariation)
{
	if( m_sound ) 
	{
		FMOD::Channel* fmod_channel;
		sfx.fmod_result = sfx.m_fmod_system->playSound(FMOD_CHANNEL_FREE, m_sound, true, &fmod_channel);
		FMOD_ERROR_CHECK else {
			float rndPitch = pitch + midrnd()*pitchVariation - pitchVariation / 2;
			
			float frequency = 1.0;
			sfx.fmod_result = fmod_channel->getFrequency(&frequency);
			FMOD_ERROR_CHECK
			sfx.fmod_result = fmod_channel->setFrequency(frequency * rndPitch);
			FMOD_ERROR_CHECK
			
			float rndVolume = volume + midrnd()*volumeVariation - volumeVariation / 2;
			float volume = 1.0;
			sfx.fmod_result = fmod_channel->getVolume(&volume);
			FMOD_ERROR_CHECK
			sfx.fmod_result = fmod_channel->setVolume(volume * rndVolume);
			FMOD_ERROR_CHECK
				
			sfx.fmod_result = fmod_channel->setLoopCount(0);
			FMOD_ERROR_CHECK
			sfx.fmod_result = fmod_channel->setPaused(false);
			FMOD_ERROR_CHECK
		}
	}
}

void Sound::play2D(const Vec& pos, float loudness, float pitch, float pitchVariation)
{
	if( m_sound ) 
	{
		FMOD::Channel* fmod_channel;
		sfx.fmod_result = sfx.m_fmod_system->playSound(FMOD_CHANNEL_FREE, m_sound, true, &fmod_channel);
		FMOD_ERROR_CHECK else {
			FMOD_VECTOR _pos[3] = { pos.x, pos.y, 0 };
			sfx.fmod_result = fmod_channel->set3DAttributes(_pos, NULL);
			FMOD_ERROR_CHECK
			
			float rndPitch = pitch + midrnd()*pitchVariation - pitchVariation / 2;
			float frequency = 1.0;
			sfx.fmod_result = fmod_channel->getFrequency(&frequency);
			FMOD_ERROR_CHECK
			sfx.fmod_result = fmod_channel->setFrequency(frequency * rndPitch);
			FMOD_ERROR_CHECK
			
			sfx.fmod_result = fmod_channel->set3DMinMaxDistance(loudness, 10000.0f);
			FMOD_ERROR_CHECK
			
			sfx.fmod_result = fmod_channel->setLoopCount(0);
			FMOD_ERROR_CHECK
			sfx.fmod_result = fmod_channel->setPaused(false);
			FMOD_ERROR_CHECK
		}
	}
}

void Sound::play2D(BaseObject* obj, float loudness, float pitch, float pitchVariation)
{
	play2D(obj->pos, loudness, pitch, pitchVariation);
}

#endif
