#include "../include/force.hpp"

void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

starwars::Character::Character(int helth, int skil, int pow, int def)
{
    this->Health = helth;
    this->lightsaberSkill = skil;
    this->forcePower = pow;
    this->Defense = def;
}

starwars::Jedi::Jedi(std::string name)
{
    this->setDefaultStats(name);
}

starwars::Jedi::~Jedi()
{}

void starwars::Jedi::setDefaultStats(std::string name)
{
    // Take default stats, adjust to fit, depending on specific character type
    this->jediName = name;
    this->forcePower += 25;
    
    /*
    std::fstream fin;
    fin.open("../characterData/jediStats.txt");
    std::string helth, skil, powr, def;
    std::getline(fin, helth);
    std::getline(fin, skil);
    std::getline(fin, powr);
    std::getline(fin, def);
    // This is a technique I found online, from the main c++ reference site and Stack Exchange, as to be expected
    [[maybe_unused]]auto [ptr1, ec1] = std::from_chars(helth.data(), helth.data() + helth.size(), this->Health);
    [[maybe_unused]]auto [ptr2, ec2] = std::from_chars(skil.data(), skil.data() + skil.size(), this->lightsaberSkill);
    [[maybe_unused]]auto [ptr3, ec3] = std::from_chars(powr.data(), powr.data() + powr.size(), this->forcePower);
    [[maybe_unused]]auto [ptr4, ec4] = std::from_chars(def.data(), def.data() + def.size(), this->defense);
    */

    /* 
    Old Code

    this->Health = std::stoi(helth);
    this->lightsaberSkill = std::stoi(skil);
    this->forcePower = std::stoi(powr);
    this->defense = std::stoi(def);
    */
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

void starwars::Character::takeDamage(int incoming)
{
    this->Health -= (incoming - this->Defense);
}

int starwars::Jedi::getHealth()
{
    return this->Health;
}

void starwars::Jedi::displayStats()
{
    std::cout << "Health: " << this->Health << "  Force Power: " << this->forcePower << " Defense: " << this->defense << std::endl;
}

starwars::Sith::Sith()
{
    this->setDefaultStats();
}

starwars::Sith::~Sith()
{}

void starwars::Sith::setDefaultStats()
{
    this->Health += 20;
    this->lightsaberSkill += 10;
    this->forcePower += 25;
    this->defense -= 10;

    /*
    this->sithName = "Darth *unintelligible nonsense*";
    std::fstream fin;
    fin.open("../characterData/sithStats.txt");
    std::string helth, skil, powr, def;
    std::getline(fin, helth);
    std::getline(fin, skil);
    std::getline(fin, powr);
    std::getline(fin, def);

    [[maybe_unused]]auto [ptr1, ec1] = std::from_chars(helth.data(), helth.data() + helth.size(), this->Health);
    [[maybe_unused]]auto [ptr2, ec2] = std::from_chars(skil.data(), skil.data() + skil.size(), this->lightsaberSkill);
    [[maybe_unused]]auto [ptr3, ec3] = std::from_chars(powr.data(), powr.data() + powr.size(), this->forcePower);
    [[maybe_unused]]auto [ptr4, ec4] = std::from_chars(def.data(), def.data() + def.size(), this->defense);
    */

    /*
    this->Health = std::stoi(helth);
    this->lightsaberSkill = std::stoi(skil);
    this->forcePower = std::stoi(powr);
    this->defense = std::stoi(def);
    */
}

int starwars::Sith::Attack()
{
    return this->lightsaberSkill;
}

void starwars::Sith::Block()
{
    this->defense += 20;
    this->lightsaberSkill -= 25;
}

void starwars::Sith::unBlock()
{
    this->defense -= 20;
    this->lightsaberSkill += 25;
}

void starwars::Sith::useForce(int power) // Potentially a kind of power that lasts forever and is ongoing?
{
    this->forcePower -= power;
}

// void starwars::Sith::takeDamage(int incoming)
// {
//     this->Health -= (incoming - this->defense);
// }

int starwars::Sith::getHealth()
{
    return this->Health;
}

starwars::Game::Game(int state)
{
    this->_state = state;
}

starwars::Game::~Game()
{}

void starwars::Game::nextState(int playerChoice, Jedi& player, Sith& enemy)
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
        this->_state = 1;
    else if (enemy.getHealth() >= 60)
    {
        this->_state = 2;
        enemy.useForce(25); // To reflect the lowered force ability
    }
    else if (enemy.getHealth() >= 40)
        this->_state = 3;
    else if (enemy.getHealth() > 0)
        this->_state = 4;
    else
        this->Win();
}

void starwars::Game::displayCurrState()
{
    std::fstream fin;
    std::string currEvent = "../eventData/event" + std::to_string(this->_state) + ".txt";
    fin.open(currEvent);
    char line[1000];
    while(!EOF)
    {
        fin.getline(line, 1000000);
        std::cout << line << std::endl;
    }
    fin.close();
}

void starwars::Game::enemyTurn(Jedi& player, Sith& enemy)
{
    if (player.getHealth() >= 70)
    {
        enemy.useForce(30);
        player.takeDamage(30);
    }
    else if (player.getHealth() >= 40 || enemy.getHealth() <= 80)
    {
        player.takeDamage(enemy.Attack());
    }
    else
        enemy.Block();
}

void starwars::Game::displayChoices()
{
    std::cout << "1. Strike with your weapon" << std::endl;
    std::cout << "2. Channel the light side of the Force" << std::endl;
    std::cout << "3. Assume a defensive stance" << std::endl;
    std::cout << "4. Return to offensive combat" << std::endl;
}

void starwars::Game::Win()
{
    this->_state = 5;
}

void starwars::Game::Lose()
{
    this->_state = 6;
}

bool starwars::Game::checkWinLose(Jedi& Player, Sith& Enemy)
{
    if (Player.getHealth() == 0)
        return true; // Loss condition
    else
        return false; // Win condition
}