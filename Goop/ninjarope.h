#ifndef NINJAROPE_H
#define NINJAROPE_H

#include "base_object.h"
#include "part_type.h"
#include "vec.h"
#include <vector>

class Sprite;
class BaseAnimator;

struct NRTimer
{
	inline NRTimer( TimerEvent* tEvent)
	{
		m_tEvent = tEvent;
		count = m_tEvent->delay + (int)(rnd() * m_tEvent->delayVariation);
	}
	
	inline void reset()
	{
		count = m_tEvent->delay + (int)(rnd() * m_tEvent->delayVariation);
	}
	
	int count;
	TimerEvent* m_tEvent;
};

class NinjaRope : public BaseObject
{
	public:

	NinjaRope(PartType* type);
	
	void shoot(Vec _pos, Vec _spd);
	void remove();

	void draw(BITMAP* where,int xOff, int yOff);
	void think();
	float getAngle();
	void addAngleSpeed(float);
	
	int getColour();
	
	bool active;
	bool attached;
	
	private:
	
	std::vector< NRTimer > timer;
	PartType* m_type;
	float m_angle;
	float m_angleSpeed;
	Sprite* m_sprite;
	BaseAnimator* m_animator;
	
	bool justCreated;
};

#endif  // _PARTICLE_H_