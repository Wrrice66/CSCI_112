#include "../include/force.hpp"
#include <cstdio>
#include <format>

void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

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

void starwars::Sith::useForce(int power)
{
    this->forcePower -= power;
}

void starwars::Sith::takeDamage(int incoming)
{
    this->Health -= incoming;
}

void starwars::Game::nextState(int playerChoice)
{
    this->state = playerChoice;
}

void starwars::Game::displayCurrState()
{
    std::fstream fin;
    std::string currEvent = "../eventData/event" + std::to_string(this->state) + ".txt";
    fin.open(currEvent);
    char line[1000];
    while(!EOF)
    {
        fin.getline(line, 1000000);
        std::cout << line << std::endl;
    }
}