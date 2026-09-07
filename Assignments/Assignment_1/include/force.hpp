#include <string>

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
}