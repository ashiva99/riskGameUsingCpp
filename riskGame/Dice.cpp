//Dice.cpp
#include "Dice.h"
#include <iostream>

using namespace std;

Dice::Dice() {
    srand(time(nullptr));
}

int Dice::roll() {
    int result = rand() % 6 + 1;
    //cout << "Dice roll result: " << result << endl;
    return result;
}
