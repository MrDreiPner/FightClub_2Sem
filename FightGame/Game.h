#ifndef GAME_H
#define GAME_H
#include "Character.h"
#include "Skills.h"

class Game
{
public:
	Game();
	virtual ~Game();
	void runGame();
	void selectChar(Skills* skills[], Character* champs[], int playCount, int& p1, int& p2, int& p3, int& p4);
	void createRoster(Character* champs[]);
	void charCreation(Skills* skills[], Character* champs[], int index);
	void selectSkills(Skills* skills[], Character* champ, int classID);
	void combat(Character champ1, Character champ2, Character champ3, Character champ4);

private:
	int state;
	int turn;
};

#endif // GAME_H