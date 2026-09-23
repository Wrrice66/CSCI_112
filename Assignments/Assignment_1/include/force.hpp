#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <format>

void clearScreen();

namespace starwars {
    class Jedi {
        private:
            std::string jediName;
            int Health;
            int lightsaberSkill;
            int forcePower;
            int defense;
        public:
            void setDefaultStats(std::string);
            int Attack();
            void Block();
            void unBlock();
            void useForce(int power);
            void takeDamage(int damage);
            int getHealth();
            void displayStats();
    };

    class Sith {
        private:
            std::string sithName;
            int Health;
            int lightsaberSkill;
            int forcePower;
            int defense;
        public:
            void setDefaultStats();
            int Attack();
            void Block();
            void unBlock();
            void useForce(int power);
            void takeDamage(int damage);
            int getHealth();
    };

    class Game {
        private:
            int state;
            std::string event0, event1, event2, event3, event4, event5;
            bool endCondition;
        public:
            void nextState(int, Sith, Jedi);
            void displayCurrState();
            void displayChoices();
            bool checkWinLose();
            void Win();
            void Lose();
            void enemyTurn(Jedi, Sith);
            Game(int = 0);
            ~Game();
    };
}