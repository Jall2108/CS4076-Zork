#include "Character.h"

Character::Character() {
    this->description = "Player Character";
}

Character::Character(string Description) {
    this->description = Description;
    health = 10;
}



Character::~Character() {

}

void Character::sethealth(int health)
{
    this->health = health;
}

int Character::gethealth() {
    return health;
}
