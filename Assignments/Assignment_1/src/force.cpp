#include "../include/force.hpp"
#include <cstddef>
#include <cstdio>
#include <format>
#include <fstream>
#include <string>

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
    std::fstream fin;
    fin.open("../characterData/jediStats.txt");
    std::string helth, skil, powr;
    std::getline(fin, helth);
    std::getline(fin, skil);
    std::getline(fin, powr);
    this->Health = std::stoi(helth);
    this->lightsaberSkill = std::stoi(skil);
    this->forcePower = std::stoi(powr);
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

int starwars::Jedi::getHealth()
{
    return this->Health;
}

void starwars::Sith::setDefaultStats()
{
    this->sithName = "Darth *unintelligible nonsense*";
    std::fstream fin;
    fin.open("../characterData/sithStats.txt");
    std::string helth, skil, powr;
    std::getline(fin, helth);
    std::getline(fin, skil);
    std::getline(fin, powr);
    this->Health = std::stoi(helth);
    this->lightsaberSkill = std::stoi(skil);
    this->forcePower = std::stoi(powr);
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