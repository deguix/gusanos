#ifndef BASE_PLAYER_H
#define BASE_PLAYER_H

struct PlayerOptions;

#include <string>

class Worm;

class BasePlayer
{
	public:
	
	BasePlayer();
	~BasePlayer();
	
	virtual void think() = 0;
	virtual void render() = 0;

	void assignWorm(Worm* worm);
	
	PlayerOptions* getOptions();
	
	protected:
	
	int deaths;
	int kills;

	Worm* m_worm;
	PlayerOptions* m_options;
};

#endif  // _BASE_PLAYER_H_
