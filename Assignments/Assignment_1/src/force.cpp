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
    std::string helth, skil, powr, def;
    std::getline(fin, helth);
    std::getline(fin, skil);
    std::getline(fin, powr);
    std::getline(fin, def);
    this->Health = std::stoi(helth);
    this->lightsaberSkill = std::stoi(skil);
    this->forcePower = std::stoi(powr);
    this->defense = std::stoi(def);
}

int starwars::Jedi::Attack()
{
    return this->lightsaberSkill;
}

void starwars::Jedi::Block()
{
    this->defense += 20;
    this->lightsaberSkill -= 25;
}

void starwars::Jedi::unBlock()
{
    this->defense -= 20;
    this->lightsaberSkill += 25;
}

void starwars::Jedi::useForce(int power)
{
    this->forcePower -= power;
}

void starwars::Jedi::takeDamage(int incoming)
{
    this->Health -= (incoming - this->defense);
}

int starwars::Jedi::getHealth()
{
    return this->Health;
}

void starwars::Jedi::displayStats()
{
    std::cout << "Health: " << this->Health << "  Force Power: " << this->forcePower << " Defense: " << this->defense << std::endl;
}

void starwars::Sith::setDefaultStats()
{
    this->sithName = "Darth *unintelligible nonsense*";
    std::fstream fin;
    fin.open("../characterData/sithStats.txt");
    std::string helth, skil, powr, def;
    std::getline(fin, helth);
    std::getline(fin, skil);
    std::getline(fin, powr);
    std::getline(fin, def);
    this->Health = std::stoi(helth);
    this->lightsaberSkill = std::stoi(skil);
    this->forcePower = std::stoi(powr);
    this->defense = std::stoi(def);
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
    this->Health -= (incoming - this->defense);
}

int starwars::Sith::getHealth()
{
    return this->Health;
}

void starwars::Game::nextState(int playerChoice, Sith enemy, Jedi player)
{
    switch (playerChoice)
    {
        case 1:
            enemy.takeDamage(player.Attack());
        case 2:
            enemy.takeDamage(35); // 35 instead of 25 to account for defense, so only lightsaber damage is affected by it
            player.useForce(25);
        case 3:
            player.Block();
        case 4:
            player.unBlock();
    }

    if (enemy.getHealth() >= 80)
        this->state = 1;
    else if (enemy.getHealth() >= 60)
        this->state = 2;
    else if (enemy.getHealth() >= 40)
        this->state = 3;
    else if (enemy.getHealth() > 0)
        this->state = 4;
    else
        this->Win();
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

void starwars::Game::enemyTurn()
{
    
}