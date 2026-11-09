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
    this->_health = helth;
    this->_lightsaberSkill = skil;
    this->_forcePower = pow;
    this->_defense = def;
}

void starwars::Character::takeDamage(int incoming) { this->_health -= (incoming - this->_defense); }

void starwars::Jedi::setDefaultStats(std::string name)
{
    // Take default stats, adjust to fit, depending on specific character type
    this->_name = name;
    this->_forcePower += 25;
}

int starwars::Jedi::Attack()
{
    return this->_lightsaberSkill;
}

void starwars::Jedi::Block() {
    this->_defense += 20;
    this->_lightsaberSkill -= 25; }

void starwars::Jedi::unBlock() {
    this->_defense -= 20;
    this->_lightsaberSkill += 25; }

void starwars::Jedi::useForce(int power) { this->_forcePower -= power; }

void starwars::Jedi::takeDamage(int incoming) { this->_health -= (incoming - this->_defense); }

int starwars::Jedi::getHealth() { return this->_health; }

void starwars::Jedi::displayStats() {
    std::cout << "Health: " << this->_health << "  Force Power: " << this->_forcePower << " Defense: " << this->_defense << std::endl; }

void starwars::Sith::setDefaultStats() {
    this->_health += 20;
    this->_lightsaberSkill += 10;
    this->_forcePower += 25;
    this->_defense -= 10; }

int starwars::Sith::Attack() { return this->_lightsaberSkill; }

void starwars::Sith::Block() {
    this->_defense += 20;
    this->_lightsaberSkill -= 25; }

void starwars::Sith::unBlock() {
    this->_defense -= 20;
    this->_lightsaberSkill += 25; }

void starwars::Sith::useForce(int power) { this->_forcePower -= power; }

void starwars::Sith::takeDamage(int incoming)
{
    this->_health -= (incoming - this->_defense);
}

int starwars::Sith::getHealth()
{
    return this->_health;
}

starwars::Game::Game(int state)
{
    this->_state = state;
}

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