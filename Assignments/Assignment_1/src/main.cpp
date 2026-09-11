#include <iostream>
#include <string>
#include "../include/force.hpp"

int main(int argc, char* argv[])
{
    starwars::Game mainGame;
    starwars::Sith Enemy;
    std::string inputName;
    std::string playerChoice;

    std::cout << "Welcome to the game." << std::endl;
    std::cout << "Enter the name of your Jedi: ";
    std::getline(std::cin, inputName);
    starwars::Jedi Player;
    Player.setDefaultStats(inputName);

    while (Player.getHealth() != 0)
    {
        mainGame.displayCurrState();
        std::getline(std::cin, playerChoice);
        mainGame.nextState(std::stoi(playerChoice));
    }
    return 0;
}