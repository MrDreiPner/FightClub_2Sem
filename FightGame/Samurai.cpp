#include "Samurai.h"
#include "Character.h"
#include <iostream>
#include <string>

Samurai::Samurai(std::string name){
	Character::setName(name);
	Character::setClass("Samurai");
	setSamuraiStats();
}

void Samurai::setSamuraiStats() {
	Character::HP = 80;
	Character::classID = 1;
	Character::stamina = 120;
	Character::poise = 60;
	std::cout << Character::charName << " the " << Character::charClass << " has been constructed with following stats:\nHP: " << Character::HP << "\nStamina: " << Character::stamina << "\nPoise: " << Character::poise << std::endl;
}

Samurai::~Samurai(){
	std::cout << Character::getName() << " the " << Character::charClass << " has been destructed" << std::endl;
}