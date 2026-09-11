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
        public:
            void setDefaultStats(std::string);
            int Attack();
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
        public:
            void setDefaultStats();
            int Attack();
            void useForce(int power);
            void takeDamage(int damage);
    };

    class Game {
        private:
            int state;
            std::string event0, event1, event2, event3, event4, event5, event6, event7;
        public:
            void nextState(int);
            void displayCurrState();
            Game(int = 0);
            ~Game();
    };
}