#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <format>
#include <limits>
#include <cstddef>
#include <cstdio>
#include <charconv>

void clearScreen();

namespace starwars {

    class Character {
        private:
            std::string name;
            int Health;
            int lightsaberSkill;
            int forcePower;
            int Defense;
        public:
            virtual void takeDamage(int damage);
            Character(int = 100, int = 50, int = 50, int = 20);
            ~Character() {};
    };


    class Jedi : public Character {
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
            // void takeDamage(int damage);
            int getHealth();
            void displayStats();
            Jedi(std::string jediName) : Character(100, 50, 50, 20) { this->setDefaultStats(jediName); };
            ~Jedi() {};
    };

    class Guardian : public Jedi {
        private:
        public:
    };

    class Consular : public Jedi {
        private:
        public:
    };

    class Sith : public Character {
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
            // void takeDamage(int damage);
            int getHealth();
            Sith() : Character(100, 50, 50, 20) { this->setDefaultStats(); };
            ~Sith() {};
    };

    class Game {
        private:
            int _state;
            std::string event0, event1, event2, event3, event4, event5;
            bool endCondition;
        public:
            void nextState(int, Jedi&, Sith&);
            void displayCurrState();
            void displayChoices();
            bool checkWinLose(Jedi&, Sith&);
            void Win();
            void Lose();
            void enemyTurn(Jedi&, Sith&);
            Game(int = 0);
            ~Game() {};
    };
}