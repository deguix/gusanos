#ifndef SFX_H
#define SFX_H

#ifdef DEDSERV
#error "Can't use this in dedicated server"
#endif //DEDSERV

#include "util/vec.h"
#include <fmod.hpp>

class BaseObject;

struct Listener
{
	Vec pos;
	Vec spd;
};

class Sfx
{
public:
		
	Sfx();
	~Sfx();
	
	void init();
	void shutDown();
	void registerInConsole();
	void think();
	void setChanObject( FMOD::Channel* chan, BaseObject* obj );
	void clear();
	Listener* newListener();
	void freeListener(Listener* listener);
	void volumeChange();
	
	operator bool(); // Returns true if it's safe to use this object
	
	FMOD_RESULT fmod_result;
	FMOD_OUTPUTTYPE m_outputMode;
	FMOD::System* m_fmod_system;
	FMOD::ChannelGroup* m_fmod_mastercg;
};

extern Sfx sfx;

#endif // _GFX_H_
