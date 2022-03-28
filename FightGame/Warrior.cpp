#include "Warrior.h"
#include "Character.h"
#include <iostream>
#include <string>

Warrior::Warrior(std::string name) {
	Character::setName(name);
	Character::setClass("Warrior");
	setWarriorStats();
}

void Warrior::setWarriorStats() {
	Character::HP = 150;
	Character::classID = 3;
	Character::stamina = 80;
	Character::poise = 80;

	std::cout << Character::charName << " the " << Character::charClass << " has been constructed with following stats:\nHP: " << Character::HP << "\nStamina: " << Character::stamina << "\nPoise: " << Character::poise << std::endl;
}

Warrior::~Warrior() {
	std::cout << Character::getName() << " the " << Character::charClass << " has been destructed" << std::endl;
}
