#ifndef VAGABOND_H
#define VAGABOND_H
#include "Character.h"
class Vagabond :
    public Character
{
public:
    Vagabond(std::string name);
    ~Vagabond();
    void setStats();

private:
};

#endif // VAGABOND_H