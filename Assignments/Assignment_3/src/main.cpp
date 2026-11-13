#include "../include/force.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[])
{
    starwars::Game mainGame(0);
    starwars::Sith* Enemy = new starwars::Sith;
    std::string inputName;
    std::string playerChoice;

    clearScreen();
    std::cout << "Welcome to the game." << std::endl;
    std::cout << "Enter the name of your Jedi: ";
    std::cin >> inputName;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    starwars::Jedi* Player = new starwars::Jedi(inputName);
    while (true) {
        std::cout << "Choose what kind of Jedi you want to be: " << std::endl;
        std::cout << "Guardian(G/g): Higher health and attack" << std::endl;
        std::cout << "Consular(C/c): Much higher Force power" << std::endl;
        std::cin >> playerChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Following line was obtained online for changing strings to lowercase because I have goldfish memory
        std::transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(), [](unsigned char c) {return std::tolower(c); });
        if (playerChoice == "g") {
            Player->~Jedi();
            new (Player) starwars::Guardian(inputName);
            break;
        }
        else if (playerChoice == "c") {
            Player->~Jedi();
            new (Player) starwars::Consular(inputName);
            break;
        }
        else {
            std::cout << "Invalid input. Please try again." << std::endl;
            continue;
        }
    }

    std::srand(std::time(nullptr));
    int enemyType = (std::rand() % 2 == 0) ? 0 : 1;
    if (enemyType == 0) {
        Enemy->~Sith();
        new (Enemy) starwars::Acolyte();
    }
    else {
        Enemy->~Sith();
        new (Enemy) starwars::Darth();
    }

    // std::cout << "DEBUG: Player health: " << Player->getHealth() << std::endl;
    // std::cout << "DEBUG: Enemy health: " << Enemy->getHealth() << std::endl;

    while (Player->getHealth() > 0 && Enemy->getHealth() > 0)
    {
        clearScreen();
        mainGame.displayCurrState();
        std::cout << "Enemy stats: \n" << Enemy << "\n" << std::endl;
        std::cout << "Your stats: \n" << Player << std::endl;
        mainGame.displayChoices();
        std::cin >> playerChoice;
        mainGame.nextState(std::stoi(playerChoice), *Player, *Enemy);
        Enemy->unBlock();
        mainGame.enemyTurn(*Player, *Enemy);
    }
    if (mainGame.checkWinLose(*Player, *Enemy))
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