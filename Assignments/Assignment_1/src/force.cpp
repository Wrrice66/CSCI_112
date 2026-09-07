#include "../include/force.hpp"

void starwars::Jedi::setDefaultStats(std::string name)
{
    this->jediName = name;
    this->Health = 100;
    this->lightsaberSkill = 50;
    this->forcePower = 75;
}

int starwars::Jedi::Attack()
{
    return this->lightsaberSkill;
}

void starwars::Jedi::useForce(int power) // Potentially a kind of power that lasts forever and is ongoing?
{
    this->forcePower -= power;
}

void starwars::Jedi::takeDamage(int incoming)
{
    this->Health -= incoming;
}

void starwars::Sith::setDefaultStats()
{
    this->sithName = "Darth *unintelligible nonsense*";
    this->Health = 120;
    this->lightsaberSkill = 60;
    this->forcePower = 75;
}

int starwars::Sith::Attack()
{
    return this->lightsaberSkill;
}

void starwars::Sith::useForce(int power) // Potentially a kind of power that lasts forever and is ongoing?
{
    this->forcePower -= power;
}

void starwars::Sith::takeDamage(int incoming)
{
    this->Health -= incoming;
}