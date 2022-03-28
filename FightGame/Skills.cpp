#include "Skills.h"
#include <iostream>
#include <string>

Skills::Skills(int i) {
	std::string skillNames[9] = { "Ichimonji","Senpou Leaping Kicks", "Flowing Water", "Piercing Strike", "Rapid Flurry", "Dirt in Your Eyes", "Heavy Cleave", "Sunder", "Barricade" };
	int ID[9] = { 0,1,2,3,4,5,6,7,8 };
	int attaMod[9] = { 50,20,0,30,15,5,60,30,0 };
	int defeMod[9] = { 0,10,40,10,15,30,-10,0,60 };
	int stamCost[9] = { 35,10,20,30,20,10,50,25,20 };
	int stamDmg[9] = { 30,10,20,10,10,40,35,50,0 };
	int poiseD[9] = { 40,30,0,20,40,30,45,50,0 };
	int poiseR[9] = { 0,10,40,10,10,30,0,0,50 };
	skillID = ID[i];
	skillName = skillNames[i];
	attMod = attaMod[i];
	defMod = defeMod[i];
	staminaCost = stamCost[i];
	staminaDmg = stamDmg[i];
	poiseDmg = poiseD[i];
	poiseRec = poiseR[i];

	std::cout << "Skill " << skillName << " constructed!" << std::endl;
}


Skills::~Skills() {
	std::cout << "Skill " << skillName << " deconstructed!" << std::endl;
}

