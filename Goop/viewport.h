#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "game.h"
#include "vec.h"
#include <allegro.h>

struct Listener;

class Viewport
{
	public:
		
	Viewport();
	~Viewport();
	
	void setDestination(BITMAP* where, int x, int y, int w, int h);
	void render();
	void setPos(float x, float y);
	void interpolateTo(float x, float y, float factor);
	void interpolateTo(Vec dest, float factor);
	
	private:
	
	BITMAP* m_dest;
	Vec m_pos;
	Listener* m_listener;
	
};

#endif // _VIEWPORT_H_
