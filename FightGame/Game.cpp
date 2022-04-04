#include <iostream>
#include <string>
#include <conio.h>
#include "Game.h"
#include "Character.h"
#include "Samurai.h"
#include "Vagabond.h"
#include "Warrior.h"
#include "Skills.h"
#include "Combat.h"
constexpr auto rosterSize = 13;

Game::Game() {
	//constructor
	state = 1;
	std::cout << "Game constructed! state: "<< state << std::endl;
	runGame();
}

Game::~Game() {
	//destructor
}

void Game::runGame() {
	char dummy = _getch();
	Character* champs[rosterSize];
	createRoster(champs);
	Skills* skills[9];
	for (int i = 0; i < 9; i++) {
		Skills* talent = new Skills(i);
		skills[i] = talent;
	}
	char sel;
	int gameMode;
	bool check = true;
//Gamemode selection
	while (check) {
		system("cls");
		std::cout << "Select a gamemode:\n(q) Bot vs. Bot\n(w) Player vs. Bot\n(e) Player vs. Player" << std::endl;
		sel = _getch();
		switch (sel) {
		case 'q': {
			gameMode = 1;
			check = false;
		}
			break;
		case 'w':{
			gameMode = 2;
			check = false;
		}
			break;
		case 'e': {
			gameMode = 3;
			check = false;
		}
			break;
		default: {
			std::cout << "Invalid input, please select a valid input\nPress any key to continue..." << std::endl;
			dummy = _getch();
		}
		}
	}
	check = true;
	int playCount = 0;
	sel = '\0';
//Determines player count
	while (check) {
		system("cls");
		std::cout << "Select player count:\n(q) 1 vs. 1\n(w) 2 vs.2" << std::endl;
		sel = _getch();
		switch (sel) {
		case 'q': {
			playCount = 1;
			check = false;
		}
				break;
		case 'w': {
			playCount = 2;
			check = false;
		}
				break;
		default: {
			std::cout << "Invalid input, please select a valid input\nPress any key to continue..." << std::endl;
			dummy = _getch();
		}
		}
	}
	int p1, p2, p3, p4;
	selectChar(skills, champs, playCount, p1, p2, p3, p4);
	Combat battle(*champs[p1], *champs[p2], *champs[p3], *champs[p4], skills);

	for (int i = 0; i < rosterSize; i++) {
		delete(champs[i]);
	}
	for (int i = 0; i < 9; i++) {
		delete(skills[i]);
	}
}

void Game::selectChar(Skills* skills[], Character* champs[], int playCount, int& p1, int& p2, int& p3, int& p4) {
	bool check = true;
	int selection = -1;
	int blocker1 = -1;
	int blocker2 = -1;
	int blocker3 = -1;
	char dummy = '\0';
	while (check) {
		//1 v 1 character selection
		if (playCount == 1) {
			while (selection < 0 || selection > rosterSize-1) {
				printRoster(champs);
				std::cout << "Select P1:" << std::endl;
				std::cin >> selection;
				if (selection < 0 || selection > rosterSize-1) {
					std::cout << "Invalid selection!\nPress any key to continue..." << std::endl;
					dummy = _getch();
				}
				else {
					blocker1 = selection;
					p1 = p2 = selection;
				}
			}
			//Custom Character creation
			if (selection >= 9) {
				charCreation(skills, champs, selection);
			}
			selection = -1;
			while (selection < 0 || selection > rosterSize-1) {
				printRoster(champs);
				std::cout << "Select P2:" << std::endl;
				std::cin >> selection;
				if (selection < 0 || selection > rosterSize-1) {
					std::cout << "Invalid selection!\nPress any key to continue..." << std::endl;
					dummy = _getch();
				}
				else if(selection == blocker1){
					std::cout << "Champion already selected!\nPress any key to continue..." << std::endl;
					dummy = _getch();
					selection = -1;
					continue;
				}
				else { p3 = p4 = selection; check = false; }
			}
			if (selection >= 9) {
				charCreation(skills, champs, selection);
			}
		}
		//2 v 2 character selection
		else {
			while (selection < 0 || selection > rosterSize-1) {
				printRoster(champs);
				std::cout << "Select P1 (Team Red):" << std::endl;
				std::cin >> selection;
				if (selection < 0 || selection > rosterSize-1) {
					std::cout << "Invalid selection!\nPress any key to continue..." << std::endl;
					dummy = _getch();
				}
				else {
					blocker1 = selection;
					p1 = selection;
				}
			}
			if (selection >= 9) {
				charCreation(skills, champs, selection);
			}
			selection = -1;
			while (selection < 0 || selection > rosterSize-1) {
				printRoster(champs);
				std::cout << "Select P3 (Team Blue):" << std::endl;
				std::cin >> selection;
				if (selection < 0 || selection > rosterSize-1) {
					std::cout << "Invalid selection!\nPress any key to continue..." << std::endl;
					dummy = _getch();
				}
				else if (selection == blocker1 || selection == blocker2 || selection == blocker3) {
					std::cout << "Champion already selected!\nPress any key to continue..." << std::endl;
					dummy = _getch();
					selection = -1;
					continue;
				}
				else {
					p3 = selection;
					blocker2 = selection;
				}
			}
			if (selection >= 9) {
				charCreation(skills, champs, selection);
			}
			selection = -1;
			while (selection < 0 || selection > rosterSize-1) {
				printRoster(champs);
				std::cout << "Select P2 (Team Red):" << std::endl;
				std::cin >> selection;
				if (selection < 0 || selection > rosterSize-1) {
					std::cout << "Invalid selection!\nPress any key to continue..." << std::endl;
					dummy = _getch();
				}
				else if (selection == blocker1 || selection == blocker2 || selection == blocker3) {
					std::cout << "Champion already selected!\nPress any key to continue..." << std::endl;
					dummy = _getch();
					selection = -1;
					continue;
				}
				else {
					p2 = selection;
					blocker3 = selection;
				}
			}
			if (selection >= 9) {
				charCreation(skills, champs, selection);
			}
			selection = -1;
			while (selection < 0 || selection > rosterSize-1) {
				printRoster(champs);
				std::cout << "Select P4 (Team Blue):" << std::endl;
				std::cin >> selection;
				if (selection < 0 || selection > rosterSize-1) {
					std::cout << "Invalid selection!" << std::endl;
					dummy = _getch();
				}
				else if (selection == blocker1 || selection == blocker2 || selection == blocker3) {
					std::cout << "Champion already selected!\nPress any key to continue..." << std::endl;
					dummy = _getch();
					selection = -1;
					continue;
				}
				else { p4 = selection; check = false; }
			}
			if (selection >= 9) {
				charCreation(skills, champs, selection);
			}
		}
	}
}

void Game::charCreation(Skills* skills[], Character* champs[], int index) {
	std::string newName;
	std::cout << "Your name: ";
	std::cin >> newName;
	int check = 0;
	int select;
	char dummy;
	while (check == 0) {
		std::cout << "Select class: Samurai(1), Warrior(2), Vagabond(3), Wretch(4):" << std::endl;
		std::cin >> select;
		switch (select) {
		case 1: {
			Samurai* tarnished = new Samurai(newName);
			selectSkills(skills, tarnished, 1);
			champs[index] = tarnished;
			check = 1;
		}
			  break;
		case 2: {
			Warrior* tarnished = new Warrior(newName);
			selectSkills(skills, tarnished, 3);
			champs[index] = tarnished;
			check = 1;
		}
			  break;
		case 3: {
			Vagabond* tarnished = new Vagabond(newName);
			selectSkills(skills, tarnished, 2);
			champs[index] = tarnished;
			check = 1;
		}
			  break;
		case 4: {
			Character* tarnished = new Character();
			tarnished->setName(newName);
			selectSkills(skills, tarnished, 4);
			champs[index] = tarnished;
			check = 1;
		}
			  break;
		default: {std::cout << "Invalid selection" << std::endl; }
		}
		std::cout << champs[index]->getName() << " the " << champs[index]->getClass() << " has entered the Arena!" << std::endl;
		std::cout << "Skill 1 = " << skills[champs[index]->getSkill1()]->getSkillName() << " Skill 2 = " << skills[champs[index]->getSkill2()]->getSkillName() << std::endl;
		std::cout << "Press any key to continue..." << std::endl;
		dummy = _getch();
	}
}

void Game::selectSkills(Skills* skills[], Character* champ, int classID) {
	bool check = true;
	int selection = -1;
	int blocker1 = -1;
	char dummy;
	while (check) {
		if (classID == 1) {
			while (selection < 0 || selection > 2) {
				system("cls");
				for (int i = 0; i < 3; i++) {
					std::cout << i << ". " << skills[i]->getSkillName() << std::endl;
				}
				std::cout << "Select Skill 1:" << std::endl;
				std::cin >> selection;
				if (selection < 0 || selection > 2) {
					std::cout << "Invalid selection!\nPress any key to continue..." << std::endl;
					dummy = _getch();
				}
				else {
					blocker1 = selection;
				}
			}
			int selection2 = -1;
			while (selection2 < 0 || selection2 > 2) {
				std::cout << "Select Skill 2:" << std::endl;
				std::cin >> selection2;
				if (selection2 < 0 || selection2 > 2) {
					std::cout << "Invalid selection!\nPress any key to continue..." << std::endl;
					dummy = _getch();
				}
				else if (selection2 == blocker1) {
					std::cout << "Champion already selected!\nPress any key to continue..." << std::endl;
					dummy = _getch();
					selection2 = -1;
					continue;
				}
				else { champ->setSkill(selection, selection2); check = false; }
			}
		}
		if (classID == 2) {
			while (selection < 3 || selection > 5) {
				system("cls");
				for (int i = 3; i < 6; i++) {
					std::cout << i << ". " << skills[i]->getSkillName() << std::endl;
				}
				std::cout << "Select Skill 1:" << std::endl;
				std::cin >> selection;
				if (selection < 3 || selection > 5) {
					std::cout << "Invalid selection!\nPress any key to continue..." << std::endl;
					dummy = _getch();
				}
				else {
					blocker1 = selection;
				}
			}
			int selection2 = -1;
			while (selection2 < 3 || selection2 > 5) {
				std::cout << "Select Skill 2:" << std::endl;
				std::cin >> selection2;
				if (selection2 < 3 || selection2 > 5) {
					std::cout << "Invalid selection!\nPress any key to continue..." << std::endl;
					dummy = _getch();
				}
				else if (selection2 == blocker1) {
					std::cout << "Champion already selected!\nPress any key to continue..." << std::endl;
					dummy = _getch();
					selection2 = -1;
					continue;
				}
				else { champ->setSkill(selection, selection2); check = false; }
			}
		}
		if (classID == 3) {
			while (selection < 6 || selection > 8) {
				system("cls");
				for (int i = 6; i < 9; i++) {
					std::cout << i << ". " << skills[i]->getSkillName() << std::endl;
				}
				std::cout << "Select Skill 1:" << std::endl;
				std::cin >> selection;
				if (selection < 6 || selection > 8) {
					std::cout << "Invalid selection!\nPress any key to continue..." << std::endl;
					dummy = _getch();
				}
				else {
					blocker1 = selection;
				}
			}
			int selection2 = -1;
			while (selection2 < 6 || selection2 > 8) {
				std::cout << "Select Skill 2:" << std::endl;
				std::cin >> selection2;
				if (selection2 < 6 || selection2 > 8) {
					std::cout << "Invalid selection!\nPress any key to continue..." << std::endl;
					dummy = _getch();
				}
				else if (selection2 == blocker1) {
					std::cout << "Skill already selected!\nPress any key to continue..." << std::endl;
					dummy = _getch();
					selection2 = -1;
					continue;
				}
				else { champ->setSkill(selection, selection2); check = false; }
			}
		}
		if (classID == 4) {
			while (selection < 0 || selection > 8) {
				system("cls");
				for (int i = 0; i < 9; i++) {
					std::cout << i << ". " << skills[i]->getSkillName() << std::endl;
				}
				std::cout << "Select Skill 1:" << std::endl;
				std::cin >> selection;
				if (selection < 0 || selection > 8) {
					std::cout << "Invalid selection!\nPress any key to continue..." << std::endl;
					dummy = _getch();
				}
				else {
					blocker1 = selection;
				}
			}
			int selection2 = -1;
			while (selection2 < 0 || selection2 > 8) {
				std::cout << "Select Skill 2:" << std::endl;
				std::cin >> selection2;
				if (selection2 < 0 || selection2 > 8) {
					std::cout << "Invalid selection!\nPress any key to continue..." << std::endl;
					dummy = _getch();
				}
				else if (selection2 == blocker1) {
					std::cout << "Skill already selected!\nPress any key to continue..." << std::endl;
					dummy = _getch();
					selection2 = -1;
					continue;
				}
				else { champ->setSkill(selection, selection2); check = false; }
			}
		}
	}
}

void Game::createRoster(Character* champs[]) {
	std::string names[] = { "Okina","Yamate", "Iji", "Hewgh", "D", "Rogier", "Coryhn", "Nephelia", "Hedwig", "Custom Character 1", "Custom Character 2", "Custom Character 3", "Custom Character 4" };
	int end = 0;
	for (int i = 0; i < 13; i++) {
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

void Game::printRoster(Character* champs[]) {
	system("cls");
	for (int i = 0; i < rosterSize; i++) {
		std::cout << i << ". " << champs[i]->getName() << " the " << champs[i]->getClass() << std::endl;
	}
}