#ifndef SKILLS_H
#define SKILLS_H
#include <string>

class Skills
{
public:
	Skills(int i);
	virtual ~Skills();
	std::string getSkillName() { return skillName; };
protected:
	int skillID{ 0 };
	std::string skillName{ 0 };
	int attMod{ 0 };
	int defMod{ 0 };
	int staminaCost{ 0 };
	int staminaDmg{ 0 };
	int poiseDmg{ 0 };
	int poiseRec{ 0 };
};

#endif // SKILLS_H
