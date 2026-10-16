#include "../include/force.hpp"

int main(int argc, char* argv[])
{
    starwars::Game mainGame(0);
    starwars::Sith Enemy;
    std::string inputName;
    std::string playerChoice;

    // clearScreen();
    std::cout << "Welcome to the game." << std::endl;
    std::cout << "Enter the name of your Jedi: ";
    std::cin >> inputName;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    starwars::Jedi Player(inputName);

    std::cout << "DEBUG: Player health: " << Player.getHealth() << std::endl;
    std::cout << "DEBUG: Enemy health: " << Enemy.getHealth() << std::endl;

    while (Player.getHealth() != 0 && Enemy.getHealth() != 0)
    {
        // clearScreen();
        mainGame.displayCurrState();
        Player.displayStats();
        mainGame.displayChoices();
        std::cin >> playerChoice;
        mainGame.nextState(std::stoi(playerChoice), Player, Enemy);
        Enemy.unBlock();
        mainGame.enemyTurn(Player, Enemy);
    }
    if (mainGame.checkWinLose(Player, Enemy))
    {
        mainGame.Win();
        // clearScreen();
        mainGame.displayCurrState();
    }
    else
    {
        mainGame.Lose();
        // clearScreen();
        mainGame.displayCurrState();
    }
    return 0;
}