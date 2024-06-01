// RiskGameSimulator.h
#ifndef RISK_GAME_SIMULATOR_H
#define RISK_GAME_SIMULATOR_H

#include <iostream>
#include <string>
#include "StatisticsKeeper.h" 
#include "Game.h"
#include <fstream>

using namespace std;

class RiskGameSimulator {
public:
    RiskGameSimulator();
    ~RiskGameSimulator();


    void get_user_input();
    void playMultipleGames();
    void play();
    void printResult();
    int numGames;
    

private:
    
    //int players;
    int gameCount = 0;
    StatisticsKeeper statsKeeper; // Object of StatisticsKeeper class
};

#endif // RISK_GAME_SIMULATOR_H
