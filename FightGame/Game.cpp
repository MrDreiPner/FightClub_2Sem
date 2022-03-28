#include <iostream>
#include <string>
#include <conio.h>
#include "Game.h"
#include "Character.h"
#include "Samurai.h"
#include "Vagabond.h"
#include "Warrior.h"
#include "Skills.h"

Game::Game() {
	//constructor
	state = 1;
	std::cout << "Game constructed! state: "<< state << std::endl;
	runGame();
}

Game::~Game() {
	//destructor
}

void Game::createRoster(Character* champs[]) {
	std::string names[10] = { "Okina","Yamate", "Iji", "Hewgh", "D", "Rogier", "Coryhn", "Nephelia", "Hedwig", "Custom Character" };
	int end = 0;
	for (int i = 0; i < 10; i++) {
		if (i < 3) {
			Samurai* tarnished = new Samurai(names[i]);
			champs[i] = tarnished;
		}
		else if (i < 6) {
			Vagabond* tarnished = new Vagabond(names[i]);
			champs[i] = tarnished;
		}
		else if (i < 9) {
			Warrior* tarnished = new Warrior(names[i]);
			champs[i] = tarnished;
		}
		else {
			Character* tarnished = new Character();
			tarnished->setName(names[i]);
			champs[i] = tarnished;
		}
	}
}

void Game::runGame() {
	char dummy = _getch();
	Character* champs[10];
	createRoster(champs);
	Skills* skills[9];
	for (int i = 0; i < 9; i++) {
		Skills* talent = new Skills(i);
		skills[i] = talent;
	}


	for (int i = 0; i < 10; i++) {
		delete(champs[i]);
	}
	for (int i = 0; i < 9; i++) {
		delete(skills[i]);
	}
}


/*std::cout << "Your name: ";
std::cin >> names[i];
int check = 0;
int select;
while (check == 0) {
	std::cout << "Select class: Samurai(1), Warrior(2), Vagabond(3), Wretch(4):" << std::endl;
	std::cin >> select;
	switch (select) {
	case 1: {
		Samurai* tarnished = new Samurai(names[i]);
		champs[i] = tarnished;
		check = 1;
	}
		  break;
	case 2: {
		Warrior* tarnished = new Warrior(names[i]);
		champs[i] = tarnished;
		check = 1;
	}
		  break;
	case 3: {
		Vagabond* tarnished = new Vagabond(names[i]);
		champs[i] = tarnished;
		check = 1;
	}
		  break;
	case 4: {
		Character* tarnished = new Character();
		tarnished->setName(names[i]);
		champs[i] = tarnished;
		check = 1;
	}
		  break;
	default: {std::cout << "Invalid selection" << std::endl; }
	}
}*/

