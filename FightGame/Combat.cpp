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
		int hp1 = champ1.getHP();
		int hp2 = champ2.getHP();
		int hp3 = champ3.getHP();
		int hp4 = champ4.getHP();
		cout << "   " << name1 << "        " << name2 << "   VS   " << name3 << "        " << name4 << "\n";
		cout << "   " << "HP: " << hp1 << gapCount(n1L,)
	}
}

void gapCount(int nameLength, int hp) {

}