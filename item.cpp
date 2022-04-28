#include "item.h"

Item::Item (string inDescription, int inWeightGrams, float inValue ) {
    this->description = inDescription;
    setWeight(inWeightGrams);
    setValue(inValue);

}

Item::Item(string description){
    this->description = description;
    this->weightGrams = 1;
    this->value = 1;
}



void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
       weightGrams = inWeightGrams;
}


void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
       value = inValue;
}

float Item::getValue(){
    return value;
}

int Item::getWeight(){
    return weightGrams;
}

/**void Item::setWeaponCheck(int isWeapon)
{
    if(isWeapon > 0 || isWeapon < 0)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
}*/

string Item::getShortDescription()
{
    return description;
}

string Item::getLongDescription()
{
    return " item(s), " + description + ".\n";
}
