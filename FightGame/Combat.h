#ifndef COMBAT_H
#define COMBAT_H
#include "Character.h"
#include "Skills.h"

class Combat
{
public:
    Combat(Character& champ1, Character& champ2, Character& champ3, Character& champ4, Skills* skillList[]);
    virtual ~Combat();
    void combatScreen(Character& champ1, Character& champ2, Character& champ3, Character& champ4, bool teams);
    void gapCount(int nameLength, int hp);
    void fight(Character& champ1, Character& champ2, Character& champ3, Character& champ4, bool teams, Skills* skillList[]);
private:

};

#endif // COMBAT_H