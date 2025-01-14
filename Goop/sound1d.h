#ifndef SOUND1D_H
#define SOUND1D_H

#ifdef DEDSERV
#error "Can't use this in dedicated server"
#endif //DEDSERV

#include "resource_list.h"
#include "glua.h"
#include <string>
#include <boost/filesystem/path.hpp>
namespace fs = boost::filesystem;

#ifdef __MINGW32__ //Fixes issue on using proper calling convention on FMODEx
	#define __CYGWIN32__
#endif
#include <fmod.hpp>
#include <fmod_errors.h>
#ifdef __MINGW32__
	#undef __CYGWIN32__
#endif

class Sound1D : public LuaObject
{
	public:
		
	Sound1D();
	~Sound1D();
	
	bool load(fs::path const& filename);
	void play( float volume = 1,float pitch = 1,float volumeVariation = 0,float pitchVariation = 0);
	
	private:
	
	FMOD::Sound * m_sound;
};

extern ResourceList<Sound1D> sound1DList;

#endif // _SOUND1D_H_
