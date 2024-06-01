//Game cpp file
#include "Game.h"

Game::Game() : countPlayers(0), players(nullptr) {}


Game::~Game() {
    delete[] players; 
}

void Game::setPlayers(int countPlayers) {
    this->countPlayers = countPlayers;
    players = new Player[countPlayers]; 
    cout << endl;
    for (int i = 0; i < countPlayers; i++) {
        string name, color = "color";
        cout << "Enter name for Player " << i + 1 << ": ";
        cin >> name;
        //players[i] = Player(name, color, i + 1); // Initialize each player        // not working
        players[i].setUser(name, color, i + 1);
        cout << players[i].getName() << endl;
    }
}

void Game::showBoard() const {
    gameboard.drawBoard(); // Draw the game board
}

void Game::chooseColor() {
    // Allow players to choose colors
    for (int i = 0; i < countPlayers; ++i) {
        cout << "Player " << i + 1 << " choose a color: ";
        string color;
        cin >> color;
        players[i].setColor(color);
    }
}

void Game::displayPlayerInfo() const {
    // Display information for each player
    for (int i = 0; i < countPlayers; ++i) {
        cout << "Player " << i + 1 << " info:\n";
        players[i].displayInfo();
    }
}

void Game::placeArmy() {
    // Place armies for each player
    int occupied = 0;
    while (occupied < 7) {
        cout << "total to be occupied is: " << 7-occupied << endl;
        for (int i = 0; i < countPlayers; ++i) {
            int choice;
            cout << endl;
            cout << players[i].getName() << " Choose your Territory to occuoy" << endl;
            cout << "1.QLD 2.NSW 3.VIC 4.SA 5.WA 6.TAS 7.NT"<< endl;
            bool validChoice = 0;
            while (!validChoice) {
                cin >> choice;
                if (choice > 7 || choice < 1 || gameboard.checkTerritory(choice) == 1) {
                    cout << "invalid or already occupied. please choose again" << endl;
                }
                else {
                    gameboard.setTerritory(choice,i+1); 
                    list<Token> tokenlist = players[i].placeArmy(choice);
                    gameboard.setArmy(choice, tokenlist); 
                    validChoice = 1;
                } 
                //cout << "Choose token to place: ";

            }
            occupied++;
            cout << "total occupied is: "<< occupied << endl;
            cout << endl;
            if (occupied == 7) break;
        }
    }
}
int Game::play() {
    cout << "Game started" << endl;
    bool endgame = false;
    int attackCount = 0;
  
    while (!endgame) {
        
        for (int i = 0; i < countPlayers; i++) {
            cout << "\nPlayer " << players[i].getName() << ", choose your option: \n";
            cout << "1. Attack\n";
            cout << "2. Pass\n";
            cout << "3. End game\n";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                attackCount++;
                cout << "Available territories for attack:\n";
                gameboard.displayAvailableTerritoriesForAttack(players[i].getTerritories());
                int territoryToAttack, territoryFromAttack;
                cout << "Choose a territory to attack: ";
                cin >> territoryToAttack;
                cout << "From which territory you want to attack?: ";
                cin >> territoryFromAttack;
                if (!gameboard.isValidAttack(players[i].getTerritories(), territoryToAttack, territoryFromAttack)) {
                    cout << "Invalid territory choice.\n Try again \n";
                    break;
                }
                else {
                    // else cout << "played" << endl;  //temp purpose
                    players[i].roll(); // attacker roll the dice
                    int* attackerDiceResults = players[i].getDiceResult(); //lets use list or array // storing 3 dice result
                    int* attackerArmyCount = gameboard.armyCount(territoryFromAttack); // counting armies, strength and returning in arrays

                    int defenderId = gameboard.getDefenderId(territoryToAttack);
                    players[gameboard.getDefenderId(territoryToAttack)].roll(); // defender roll the dice
                    int* defenderDiceResults = players[gameboard.getDefenderId(territoryToAttack)].getDiceResult();
                    //cout << "\n\ngetting defender id for check" << gameboard.getDefenderId(territoryToAttack) << endl;
                    int* defenderArmyCount = gameboard.armyCount(territoryToAttack);

                    int attackerDiceResult = 0, defenderDiceResult = 0;
                    for (int k = 0; k < 3; ++k) {
                        attackerDiceResult += attackerDiceResults[k] * attackerArmyCount[k];
                        if (attackerArmyCount[k] != 0) 
                            cout << "Dice result for attacker "<<k<<": " << attackerDiceResults[k] << " army count: " << attackerArmyCount[k] << endl;
                    }

                    cout << endl;
                    for (int k = 0; k < 3; ++k) {
                        defenderDiceResult += defenderDiceResults[k] * defenderArmyCount[k];
                        if (defenderArmyCount[k] != 0) 
                            cout << "Dice result for defender " <<k<<": "<< defenderDiceResults[k] << " army count: "<<defenderArmyCount[k]<<endl;
                    }
                    cout << endl;

                    cout << "Attacker's dice result: " << attackerDiceResult << endl;
                    cout << "Defender's dice result: " << defenderDiceResult << endl;
                    if (attackerDiceResult > defenderDiceResult) { 
                        cout << "Attacker wins!\n";
                        int attackerTerritoryCount = players[i].getTerritories().size();
                        if (attackerTerritoryCount + 1 >= 5) {
                            cout << players[i].getName() << " is the winner" << endl;
                            endgame = true;
                            this->winnerName = players[i].getName();
                            return attackCount;
                        }
                        else{
                        ///////////////////////////////////////////////////////////

                        int defenderTroopDecrease = gameboard.setAttackedArmy(i + 1, defenderId + 1, territoryFromAttack, territoryToAttack);
                        players[i].incrementTerritory(territoryToAttack);
                        players[defenderId].decrementTerritory(territoryToAttack, defenderTroopDecrease);

                        //gameboard.resolvegameboard(players[i], territoryChoice);
                        //update troop stregnth methode need to implement in player.cpp
                        }
                    }
                    else {
                        cout << "Defender wins!\n";

                        //gameboard.retreatgameboard(players[i]);
                        //update troop stregnth methode need to implement in player.cpp
                    }
                }
                break;
            case 2:
                cout << "Player " << players[i].getName() << " has passed.\n";
                break;
            case 3:
                cout << "Player " << players[i].getName() << " has ended the game.\n";
                endgame = true;
                break;
            default:
                cout << "Invalid choice. Please choose again.\n";
                break;
            }

            if (endgame)
                break; 
            else if (endgame) { break; } //(no.of territory by player) {

            } // include troop stren
        }
    return attackCount;
    }
//}


string Game::results() const {
    cout << winnerName << " is the winner" << endl;
    cout << "game ended" << endl;
    return winnerName;
    // Display game results
}
