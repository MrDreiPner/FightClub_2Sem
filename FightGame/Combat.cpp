#include "Combat.h"
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

Combat::Combat(Character& champ1, Character& champ2, Character& champ3, Character& champ4, Skills* skillList[]) {
	bool teams;
	if (&champ1 != &champ2 && &champ3 != &champ4) {
		cout << champ1.getName() << " and " << champ2.getName() << " VS " << champ3.getName() << " and " << champ4.getName() << endl;
		teams = true;
	}
	else {
		cout << champ1.getName() << " VS " << champ3.getName() << endl;
		teams = false;
	}
	cout << "Press any key to continue..." << endl;
	_getch();
	combatScreen(champ1, champ2, champ3, champ4, teams);
	cout << "Press any key to continue..." << endl;
	_getch();
	fight(champ1, champ2, champ3, champ4, teams, skillList);
}

Combat::~Combat() {
	//destructor
}

void Combat::combatScreen(Character& champ1, Character& champ2, Character& champ3, Character& champ4, bool teams) {
	if (teams) {
		string name1 = champ1.getName();	int n1L = name1.length();
		string name2 = champ2.getName();	int n2L = name2.length();
		string name3 = champ3.getName();	int n3L = name3.length();
		string name4 = champ4.getName();	int n4L = name4.length();
		int hp1 = champ1.getHP(); int st1 = champ1.getST();
		int hp2 = champ2.getHP(); int st2 = champ2.getST();
		int hp3 = champ3.getHP(); int st3 = champ3.getST();
		int hp4 = champ4.getHP(); int st4 = champ4.getST();
		cout << "   " << name1 << "        " << name2 << "        VS   " << name3 << "        " << name4 << "\n";
		cout << "   " << "HP: " << hp1; gapCount(n1L, hp1); cout << "HP: " << hp2; gapCount(n2L, hp2); cout << "     ";
		cout << "HP: " << hp3; gapCount(n3L, hp3); cout << "HP: " << hp4 << "\n";
		cout << "   " << "ST: " << st1; gapCount(n1L, st1); cout << "ST: " << st2; gapCount(n2L, st2); cout << "     ";
		cout << "ST: " << st3; gapCount(n3L, st3); cout << "ST: " << st4 << "\n";
	}
	else {
		string name1 = champ1.getName();	int n1L = name1.length();
		string name3 = champ3.getName();	int n3L = name3.length();
		int hp1 = champ1.getHP(); int st1 = champ1.getST();
		int hp3 = champ3.getHP(); int st3 = champ3.getST();
		cout << "   " << name1 << "        VS   " << name3 << "        " << "\n";
		cout << "   " << "HP: " << hp1; gapCount(n1L, hp1); cout << "     ";
		cout << "HP: " << hp3; cout << "\n";
		cout << "   " << "ST: " << st1; gapCount(n1L, st1); cout << "     ";
		cout << "ST: " << st3; cout << "\n";
	}
}

void Combat::gapCount(int nameLength, int stat) {
	int wantLength = 8;
	int finalLength;
	int nameHpRatio = 7 - nameLength;
	finalLength = wantLength - nameHpRatio;
	if (stat >= 10 && stat < 100)
		finalLength++;
	else if (stat < 10)
		finalLength += 2;
	for (int i = 0; i < finalLength; i++) {
		cout << " ";
	}
}

void Combat::fight(Character& champ1, Character& champ2, Character& champ3, Character& champ4, bool teams, Skills* skillList[]) {
	int startHP1 = champ1.getHP();
	int startHP2 = champ2.getHP();
	int startHP3 = champ3.getHP();
	int startHP4 = champ4.getHP();
	if (teams) {
		int roll1, roll2;
		while (champ1.getHP() > 0 && champ3.getHP() > 0) {
			system("cls");
			roll1 = rand() % 2;
			roll2 = rand() % 2;
			if (roll1 == 0) {
				champ1.useSkill(skillList, champ1.getSkill1(), roll2 == 0 ? champ3.getSkill1() : champ3.getSkill2(), champ3);
			}
			else {
				champ1.useSkill(skillList, champ1.getSkill2(), roll2 == 0 ? champ3.getSkill1() : champ3.getSkill2(), champ3);
			}
			if (roll2 == 0) {
				champ3.useSkill(skillList, champ3.getSkill1(), roll1 == 0 ? champ1.getSkill1() : champ1.getSkill2(), champ1);
			}
			else {
				champ3.useSkill(skillList, champ3.getSkill2(), roll1 == 0 ? champ1.getSkill1() : champ1.getSkill2(), champ1);
			}
			combatScreen(champ1, champ2, champ3, champ4, teams);
			cout << "\nPress any key to continue!" << endl;
			_getch();
		}
	}
	else {
		while (champ1.getHP() > 0 && champ3.getHP() > 0) {
			system("cls");
			combatScreen(champ1, champ2, champ3, champ4, teams);
			faceoff(champ1, champ3, skillList);
			if (champ1.getHP() <= 0 && champ3.getHP() <= 0) {
				cout << "It is a draw! Both fighters get healed!" << endl;
				champ1.setHP(startHP1);
				champ3.setHP(startHP3);
				combatScreen(champ1, champ2, champ3, champ4, teams);
			}
			else if (champ1.getHP() <= 0) {
				combatScreen(champ1, champ2, champ3, champ4, teams);
				cout << champ3.getName() << " is VICTORIOUS!\n" << champ1.getName() << " DIED!" << endl;
			}
			else if (champ3.getHP() <= 0) {
				combatScreen(champ1, champ2, champ3, champ4, teams);
				cout << champ1.getName() << " is VICTORIOUS!\n" << champ3.getName() << " DIED!" << endl;
			}
		}
	}

}

void Combat::faceoff(Character& champ1, Character& champ3, Skills* skillList[]) {
	int roll1, roll2;
	roll1 = rand() % 2;
	roll2 = rand() % 2;
	if (roll1 == 0) {
		champ1.useSkill(skillList, champ1.getSkill1(), roll2 == 0 ? champ3.getSkill1() : champ3.getSkill2(), champ3);
	}
	else {
		champ1.useSkill(skillList, champ1.getSkill2(), roll2 == 0 ? champ3.getSkill1() : champ3.getSkill2(), champ3);
	}
	if (roll2 == 0) {
		champ3.useSkill(skillList, champ3.getSkill1(), roll1 == 0 ? champ1.getSkill1() : champ1.getSkill2(), champ1);
	}
	else {
		champ3.useSkill(skillList, champ3.getSkill2(), roll1 == 0 ? champ1.getSkill1() : champ1.getSkill2(), champ1);
	}
	cout << "\nPress any key to continue!" << endl;
	_getch();
}


