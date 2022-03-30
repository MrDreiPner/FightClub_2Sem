#include "Character.h"
#include <iostream>
#include <string>

Character::Character() {
	//Character fill
	charName = "NoName";
	charClass = "Wretch";
	HP = 100;
	stamina = 100;
	poise = 60;
	classID = 4;
	int chance = rand() % 9;
	skill1 = chance;
	while (chance == Character::skill1) {
		chance = rand() % 9;
	}
	skill2 = chance;
	//std::cout << charName << " the " << charClass << " has been constructed with following stats:\nHP: " << HP << "\nStamina: " << stamina << "\nPoise: " << poise << std::endl;
}

Character::~Character() {
	//std::cout << charName << " the " << charClass << " has been destructed" << std::endl;
	//Character destructor
}

void Character::useSkill(int skill, Character& enemy) {
	//enemy.setHP
}