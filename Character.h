#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
protected:
    friend class item;
    string description;
    int currentHealth;

    int health;
    int Durability;
    virtual void sethealth(int sethealth)=0;
    int gethealth();

public:
    Character();
    Character(string description);

    virtual ~Character();
    inline string getDescription()
    {
        return description;
    }

};

#endif
