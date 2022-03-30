#ifndef SAMURAI_H
#define SAMURAI_H
#include "Character.h"
#include <string>

class Samurai :
    public Character
{
public:
    Samurai(std::string name);
    ~Samurai();
    void setStats();
    
private:
};
#endif // SAMURAI_H
