#include "../include/force.hpp"

int main(int argc, char* argv[])
{
    starwars::Game mainGame;
    starwars::Sith Enemy;
    std::string inputName;
    std::string playerChoice;

    std::cout << "Welcome to the game." << std::endl;
    std::cout << "Enter the name of your Jedi: ";
    std::cin >> inputName;
    starwars::Jedi Player;
    Player.setDefaultStats(inputName);

    while (!mainGame.checkWinLose())
    {
        mainGame.displayCurrState();
        Player.displayStats();
        mainGame.displayChoices();
        std::cin >> playerChoice;
        mainGame.nextState(std::stoi(playerChoice), Enemy, Player);
        if (Player.getHealth() == 0)
            mainGame.Lose();
        else if (Enemy.getHealth() == 0)
            mainGame.Win();
        else
            continue;
    }
    return 0;
}