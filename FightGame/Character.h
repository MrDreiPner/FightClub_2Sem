#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character
{
public:
	Character();
	virtual ~Character();
	//virtual void calculateStats(int HP, int FP, int stamina, int poise);
	virtual std::string getName() { return charName; };
	virtual void setClass(std::string newClass) { charClass = newClass; };
	virtual void setName(std::string name) { charName = name; };
	virtual void useSkill(int selSkill, Character& enemy);

protected:
	std::string charName;
	std::string charClass;
	int classID;
	int skill1{ 0 };
	int skill2{ 0 };
	int HP;
	int stamina;
	int poise;
};

#endif // CHARACTER_H
