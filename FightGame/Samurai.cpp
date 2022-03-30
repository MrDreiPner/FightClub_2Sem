#include "Samurai.h"
#include "Character.h"
#include <iostream>
#include <string>

Samurai::Samurai(std::string name){
	Character::setName(name);
	Character::setClass("Samurai");
	setStats();
}

void Samurai::setStats() {
	Character::HP = 80;
	Character::classID = 1;
	Character::stamina = 120;
	Character::poise = 60;
	int chance = rand() % 3;
	Character::skill1 = chance;
	while (chance == Character::skill1) {
		chance = rand() % 3;
	}
	Character::skill2 = chance;

	//std::cout << Character::charName << " the " << Character::charClass << " has been constructed with following stats:\nHP: " << Character::HP << "\nStamina: " << Character::stamina << "\nPoise: " << Character::poise << std::endl;
	//std::cout << "Skill 1 = " << skill1 << " Skill 2 = " << skill2 << std::endl;
}

Samurai::~Samurai(){
	//std::cout << Character::getName() << " the " << Character::charClass << " has been destructed" << std::endl;
}