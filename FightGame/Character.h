#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "Skills.h"

class Character
{
public:
	Character();
	virtual ~Character();
	virtual std::string getName() { return charName; };
	virtual std::string getClass() { return charClass; };
	virtual int getSkill1() { return skill1; };
	virtual int getSkill2() { return skill2; };
	int getClassID() { return classID; };
	int getHP() { return HP; };
	int getST() { return stamina; };
	int getPoi() { return poise; };
	void setSkill(int setSkill1, int setSkill2) { skill1 = setSkill1; skill2 = setSkill2; };
	virtual void setClass(std::string newClass) { charClass = newClass; };
	virtual void setName(std::string name) { charName = name; };
	void setHP(int dmg) { HP = dmg; }; 
	void setST(int dmg) { stamina = dmg; };
	virtual void useSkill(Skills* skillList[], int selSkill, int enemySkill, Character& enemy);
	void setLoss() { loses++; };
	void setWin() { wins++; };
	void setDraw() { draws++; };
	int getLoss() { return loses; };
	int getWin() { return wins; };
	int getDraw() { return draws; };
protected:
	std::string charName;
	std::string charClass;
	int classID;
	int skill1{ 0 };
	int skill2{ 0 };
	int HP;
	int stamina;
	int poise;
	int wins{ 0 };
	int loses{ 0 };
	int draws{ 0 };
};

#endif // CHARACTER_H
