#include "Vagabond.h"
#include "Character.h"
#include <iostream>
#include <string>

Vagabond::Vagabond(std::string name) {
	Character::setName(name);
	Character::setClass("Vagabond");
	setVagabondStats();
}

void Vagabond::setVagabondStats() {
	Character::HP = 100;
	Character::classID = 2;
	Character::stamina = 90;
	Character::poise = 70;
	std::cout << Character::charName << " the " << Character::charClass << " has been constructed with following stats:\nHP: " << Character::HP << "\nStamina: " << Character::stamina << "\nPoise: " << Character::poise << std::endl;
}

Vagabond::~Vagabond() {
	std::cout << Character::getName() << " the " << Character::charClass << " has been destructed" << std::endl;
}
