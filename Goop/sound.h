#ifndef SOUND_H
#define SOUND_H

#ifdef DEDSERV
#error "Can't use this in dedicated server"
#endif //DEDSERV

#include "resource_list.h"
#include "util/vec.h"
#include "glua.h"
#include <string>
#include <boost/filesystem/path.hpp>
namespace fs = boost::filesystem;

#ifdef __MINGW32__ //Fixes issue on using proper calling convention on FMODEx while using mingw (for some reason)
	#define __CYGWIN32__
#endif
#include <fmod.hpp>
#ifdef __MINGW32__
	#undef __CYGWIN32__
#endif

class BaseObject;

class Sound : public LuaObject
{
	public:
		
	Sound();
	~Sound();
	
	bool load(fs::path const& filename);
	void play( float volume = 1,float pitch = 1,float volumeVariation = 1,float pitchVariation = 1);
	void play2D(const Vec& pos, float loudness = 100, float pitch = 1, float pitchVariation = 1);
	void play2D( BaseObject* obj, float loudness = 100, float pitch = 1, float pitchVariation = 1);
	
	private:
	
	FMOD::Sound * m_sound;
};

extern ResourceList<Sound> soundList;

#endif // _SOUND_H_
