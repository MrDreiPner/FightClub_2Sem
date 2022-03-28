#ifndef GAME_H
#define GAME_H
#include "Character.h"

class Game
{
public:
	Game();
	virtual ~Game();
	void runGame();
	void createRoster(Character* champs[]);
private:
	int state;
};

#endif // GAME_H