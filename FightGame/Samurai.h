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
    void setSamuraiStats();
    
private:
};
#endif // SAMURAI_H
