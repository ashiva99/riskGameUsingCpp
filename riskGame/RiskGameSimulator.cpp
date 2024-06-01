// RiskGameSimulator.cpp
#include "RiskGameSimulator.h"

RiskGameSimulator::RiskGameSimulator() {

     numGames=0;
     //players = 0;
    
}

RiskGameSimulator::~RiskGameSimulator() {}

void RiskGameSimulator::get_user_input() {

    std::cout << "Enter the number of games to play: ";
    std::cin >> numGames;
    

    //outputFile = "output.txt";
}

void RiskGameSimulator::playMultipleGames() {

        gameCount++;
        this->play();

    cout << "Play multiple games is completed\n" << endl;
    //statsKeeper.print_statistics();
}

void RiskGameSimulator::play() {
    Game* myGame = new Game;
    cout << "Enter num of players: ";
    int players;
    do {
        cin >> players;
        if (players < 4 && players>1)
            myGame->setPlayers(players);
        else cout << "you must select players between 2 and 4" << endl;
    } while (!(players < 4 && players>0));
    cout << "num of players: " << players << " num of games: " << numGames;
    //myGame->setPlayers(players);
    myGame->showBoard();
    myGame->chooseColor();
    //Game starts
    myGame->placeArmy(); 
    myGame->displayPlayerInfo();
    int attackCount = myGame->play();
    string winnerName = myGame->results();
    statsKeeper.update_statistics(numGames, players, attackCount, gameCount, winnerName);
    cout << "game ended in simulator\n";
    this->printResult();
    delete myGame;
}


void RiskGameSimulator::printResult() {
    cout << "print result is called from main method. calling the real print statistics" << endl;
    statsKeeper.print_statistics();
}