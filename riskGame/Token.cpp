//Token.cpp
#include "Token.h"


int Token::getTroopValue() const{
    return troopValue;
}

Infantry::Infantry() : Token(1, "Green") {}

void Infantry::show() {
    cout << "Infantry - Troop: " << troopValue << ", Color: " << color << endl;
}


Cavalry::Cavalry() : Token(5, "Blue") {}

void Cavalry::show() {
    cout << "Cavalry - Troop: " << troopValue << ", Color: " << color << endl;
}

Artillery::Artillery() : Token(10, "Red") {}

void Artillery::show() {
    cout << "Artillery - Troop: " << troopValue << ", Color: " << color << endl;
}
