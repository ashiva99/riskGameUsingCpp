//Game.h
#ifndef GAME_H
#define GAME_H

#include "GameBoard.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <list>

using namespace std;

class Game {
    GameBoard gameboard;
    Player* players;
    int countPlayers;
    string winnerName;
public:
    Game();
    ~Game();
    void setPlayers(int countPlayers);
    void showBoard() const;
    void chooseColor();
    void displayPlayerInfo() const;
    void placeArmy();
    int play();
    string results() const;
};

#endif
