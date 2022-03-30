#include "Vagabond.h"
#include "Character.h"
#include <iostream>
#include <string>

Vagabond::Vagabond(std::string name) {
	Character::setName(name);
	Character::setClass("Vagabond");
	setStats();
}

void Vagabond::setStats() {
	Character::HP = 100;
	Character::classID = 2;
	Character::stamina = 90;
	Character::poise = 70;
	int chance = (rand() % 3) + 3;
	Character::skill1 = chance;
	while (chance == Character::skill1) {
		chance = (rand() % 3) + 3;
	}
	Character::skill2 = chance;
	//std::cout << Character::charName << " the " << Character::charClass << " has been constructed with following stats:\nHP: " << Character::HP << "\nStamina: " << Character::stamina << "\nPoise: " << Character::poise << std::endl;
	//std::cout << "Skill 1 = " << skill1 << " Skill 2 = " << skill2 << std::endl;
}

Vagabond::~Vagabond() {
	//std::cout << Character::getName() << " the " << Character::charClass << " has been destructed" << std::endl;
}
