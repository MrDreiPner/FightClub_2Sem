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

void Character::useSkill(Skills* skillList[], int skill, int enemySkill, Character& enemy) {
	std::cout << charName << " used " << skillList[skill]->getSkillName() << " against " << enemy.getName() << "`s " << skillList[enemySkill]->getSkillName() << "!" << std::endl;
	int attValue = skillList[skill]->getAttMod();
	if (stamina < 0)
		attValue /= 2;
	int newEnPoi = enemy.getPoi() - skillList[skill]->getPoiDmg();
	if (enemy.getPoi() < 10) {
		std::cout << enemy.getName() << "´s poise is broken! They take double damage!" << std::endl;
		attValue *= 2;
	}
	int defValue = skillList[enemySkill]->getDefMod() / 2;
	if (enemy.getST() < 0)
		defValue /= 2;
	int damage = attValue - defValue;
	int newEnHP = enemy.getHP() - damage;
	if (newEnHP < enemy.getHP()) {
		enemy.setHP(newEnHP);
		std::cout << enemy.getName() << " took " << damage << " damage!" << std::endl;
	}
	else
		std::cout << enemy.getName() << " took no damage!" << std::endl;
	stamina -= skillList[skill]->getStaCost();
	poise += skillList[skill]->getPoiRec();
	stamina += 10;
	poise += 5;
}