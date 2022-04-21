#ifndef DEDSERV

#include "sound1d.h"

#include "sfx.h"
#include "resource_list.h"
#include "util/math_func.h"

#include <string>
#include <iostream>
#include <boost/filesystem/path.hpp>
namespace fs = boost::filesystem;

#include <allegro.h>
//#include "text.h"

#include <fmod.hpp>

#define FMOD_ERROR_CHECK \
	if (sfx.fmod_result != FMOD_OK) { \
		cerr << "* FMOD ERROR " << FMOD_ErrorString(sfx.fmod_result) << endl; \
		return; \
	}

ResourceList<Sound1D> sound1DList;

Sound1D::Sound1D()
{
	m_sound = nullptr;
}

Sound1D::~Sound1D()
{
	if (m_sound) {
		sfx.fmod_result = m_sound->release();
		FMOD_ERROR_CHECK;
	}
}

bool Sound1D::load(fs::path const& filename)
{	
	//cerr << "Loading sound: " << filename.native() << endl;
	
	sfx.fmod_result = sfx.m_fmod_system->createSound(filename.native().c_str(), FMOD_2D | FMOD_LOWMEM, 0, &m_sound); //FSOUND_FORCEMONO
	if (sfx.fmod_result != FMOD_OK) {
		cerr << "* FMOD ERROR File not found or error while loading: " << filename.native().c_str() << endl;
		return false;
	}
	if ( m_sound )
	{
		return true;
	}
	return false;
}

void Sound1D::play(float volume,float pitch, float volumeVariation, float pitchVariation)
{
	if( m_sound ) 
	{
		FMOD::Channel* fmod_channel = nullptr;
		sfx.fmod_result = sfx.m_fmod_system->playSound(FMOD_CHANNEL_FREE, m_sound, true, &fmod_channel);
		FMOD_ERROR_CHECK else {
			float rndPitch = pitch + midrnd()*pitchVariation;
			
			float frequency = 1.0;
			sfx.fmod_result = fmod_channel->getFrequency(&frequency);
			FMOD_ERROR_CHECK
			sfx.fmod_result = fmod_channel->setFrequency(frequency * rndPitch);
			FMOD_ERROR_CHECK
			
			float rndVolume = volume + midrnd()*volumeVariation;
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

#endif
