//Gameboard.h
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include<map>
#include<list>
#include <set>
#include "Token.h"
using namespace std;

class GameBoard {
    int adjacencyMatrix[7][7];
    map<int, list<Token>> Territory; // Key is Trritory and Value has list of tokens
    map<int, int> whosTerritory; // Key is Trritory and Value is Player id
    map<int, string> territories = {
        {1, "1. QLD"},
        {2, "2. NSW"},
        {3, "3. VIC"},
        {4, "4. SA "},
        {5, "5. WA "},
        {6, "6. TAS"},
        {7, "7. NT "}
    };
public:
    GameBoard();
    void drawBoard() const;
    void setTerritory(int territory, int playerId); //, Token* army
    void setArmy(int choice, const list<Token> tokens);
    bool checkTerritory(int territory);
    void getInfo();
    void displayAvailableTerritoriesForAttack(set <int> territoryPlayerList);
    bool isValidAttack(set <int> territoryPlayerList, int territoryChoice, int territoryFromAttack);
    int getDefenderId(int territoryToAttack);
    int* armyCount(int territoryArmy);
    int setAttackedArmy(int attacker, int defender, int aT, int dT);
};

#endif
