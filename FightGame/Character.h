#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character
{
public:
	Character();
	virtual ~Character();
	virtual std::string getName() { return charName; };
	virtual std::string getClass() { return charClass; };
	virtual int getSkill1() { return skill1; };
	virtual int getSkill2() { return skill2; };
	void setSkill(int setSkill1, int setSkill2) { skill1 = setSkill1; skill2 = setSkill2; };
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
