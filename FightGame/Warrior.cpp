#include "Warrior.h"
#include "Character.h"
#include <iostream>
#include <string>

Warrior::Warrior(std::string name) {
	Character::setName(name);
	Character::setClass("Warrior");
	setStats();
}

void Warrior::setStats() {
	Character::HP = 150;
	Character::classID = 3;
	Character::stamina = 80;
	Character::poise = 80;
	int chance = (rand() % 3) + 6;
	Character::skill1 = chance;
	while (chance == Character::skill1) {
		chance = (rand() % 3) + 6;
	}
	Character::skill2 = chance;

	//std::cout << Character::charName << " the " << Character::charClass << " has been constructed with following stats:\nHP: " << Character::HP << "\nStamina: " << Character::stamina << "\nPoise: " << Character::poise << std::endl;
	//std::cout << "Skill 1 = " << skill1 << " Skill 2 = " << skill2 << std::endl;
}

Warrior::~Warrior() {
	//std::cout << Character::getName() << " the " << Character::charClass << " has been destructed" << std::endl;
}
