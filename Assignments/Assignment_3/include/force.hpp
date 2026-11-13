#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <format>
#include <limits>
#include <cstddef>
#include <cstdio>
#include <charconv>
#include <ctime>

void clearScreen();

namespace starwars {

    class Character {
        protected:
            std::string _name;
            int _health;
            int _lightsaberSkill;
            int _forcePower;
            int _defense;
        public:
            virtual void takeDamage(int damage);
            Character(int = 100, int = 50, int = 50, int = 20);
            ~Character() {};
            Character operator+(Character const&);
            Character operator-(Character const&);
            friend std::ostream& operator<<(std::ostream&, Character const&);
            bool operator==(Character const&);
            bool operator!=(Character const&);
            bool operator<(Character const&);
            bool operator>(Character const&);
    };
    std::ostream& operator<<(std::ostream&, Character const&);


    class Jedi : public Character {
        private:
            // std::string jediName;
            // int Health;
            // int lightsaberSkill;
            // int forcePower;
            // int defense;
        public:
            void setDefaultStats(std::string);
            int Attack();
            void Block();
            void unBlock();
            void useForce(int power);
            void takeDamage(int damage);
            int getHealth();
            void displayStats();
            Jedi();
            Jedi(std::string jediName) : Character(100, 50, 50, 20) { this->setDefaultStats(jediName); }
            ~Jedi() {};
    };

    class Guardian : public Jedi {
        public:
            void setDefaultStats();
            Guardian(std::string jediName) : Jedi(jediName) { this->setDefaultStats(); }
            ~Guardian();
    };

    class Consular : public Jedi {
        public:
            void setDefaultStats();
            Consular(std::string jediName) : Jedi(jediName) { this->setDefaultStats(); }
            ~Consular();
    };

    class Sith : public Character {
        private:
            // std::string sithName;
            // int Health;
            // int lightsaberSkill;
            // int forcePower;
            // int defense;
        public:
            void setDefaultStats();
            int Attack();
            void Block();
            void unBlock();
            void useForce(int power);
            void takeDamage(int damage);
            int getHealth();
            Sith() : Character(100, 50, 50, 20) { this->setDefaultStats(); }
            ~Sith() {};
    };

    class Acolyte : public Sith {
        public:
            void setDefaultStats();
            Acolyte() : Sith() {}
            ~Acolyte();
    };

    class Darth : public Sith {
        public:
            void setDefaultStats();
            Darth() : Sith() {};
            ~Darth();
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