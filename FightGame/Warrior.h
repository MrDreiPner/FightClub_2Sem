#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.h"
class Warrior :
    public Character
{
public:
    Warrior(std::string name);
    ~Warrior();
    void setStats();
private:
};

#endif // WARRIOR_H