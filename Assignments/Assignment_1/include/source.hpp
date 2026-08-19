#include <string>

namespace starwars {
    class Jedi {
        std::string jediName;
        int Health;
        int lightsaberSkill;
        int forcePower;
        void setDefaultStats();
        int Attack();
        void useForce(int power);
        void takeDamage(int damage);
    };

    class Sith {
        std::string sithName;
        int Health;
        int lightsaberSkill;
        int forcePower;
        void setDefaultStats();
        int Attack();
        void useForce(int power);
        void takeDamage(int damage);
    };
}