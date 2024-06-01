//GameBoard cpp file

#include<iostream>
#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard() {

    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            adjacencyMatrix[i][j] = 0;
        }
    }
    adjacencyMatrix[0][1] = 1;
    adjacencyMatrix[0][3] = 1;
    adjacencyMatrix[0][6] = 1;
    adjacencyMatrix[1][0] = 1;
    adjacencyMatrix[1][2] = 1;
    adjacencyMatrix[1][3] = 1;
    adjacencyMatrix[2][1] = 1;
    adjacencyMatrix[2][3] = 1;
    adjacencyMatrix[3][0] = 1;
    adjacencyMatrix[3][1] = 1;
    adjacencyMatrix[3][2] = 1;
    adjacencyMatrix[3][4] = 1;
    adjacencyMatrix[3][6] = 1;
    adjacencyMatrix[4][3] = 1;
    adjacencyMatrix[4][6] = 1;
    adjacencyMatrix[6][0] = 1;
    adjacencyMatrix[6][3] = 1;
    adjacencyMatrix[6][4] = 1;
}

void GameBoard::drawBoard() const{
    cout << "Game Board:\n\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i == 0) {
                if(j==0)
                    cout <<"STATES ";
                else
                    cout << territories.at(j) << " ";
            }
            else if (j == 0 && i!=0) {
                cout << territories.at(i) << " ";
            }
            else {
                cout << "   " << adjacencyMatrix[i-1][j-1] << "   ";
            }
            
        }
        cout << std::endl;
    }
    cout << endl;
}


void GameBoard::setTerritory(int territory, int playerId) {
    whosTerritory.insert({ territory, playerId });
    Territory.insert({ territory, {} });
}

void GameBoard::setArmy(int choice,const list<Token> tokens) {
    for (const Token& token : tokens) {
        Territory[choice].push_back(token);
    }
    
}

bool GameBoard::checkTerritory(int territory) {
    return Territory.count(territory)>0;
}

void GameBoard::displayAvailableTerritoriesForAttack(set <int> territoryPlayerList) {
    for (auto& territory : territories) {
        if (!territoryPlayerList.count(territory.first) == 1) {
            cout << territory.second << endl; 
        }
    }
}

bool GameBoard::isValidAttack(set<int> territoryPlayerList, int territoryChoice, int territoryFromAttack) {
    // Check if territoryChoice is not in territoryPlayerList
    if (territoryPlayerList.count(territoryChoice) > 0) {
        cout << "You already own Territory " << territoryChoice << ". Choose a different territory to attack." << endl;
        return false;
    }

    // Check if territoryChoice is a valid territory
    if (territories.find(territoryChoice) == territories.end()) {
        cout << "Invalid territory choice. Please choose a territory from 1 to 7." << endl;
        return false;
    }


        // Check if there's an adjacency between territoryChoice and i + 1
        if (adjacencyMatrix[territoryChoice - 1][territoryFromAttack-1] == 1) {
            // Check if territory i + 1 is owned by the player
            if (territoryPlayerList.count(territoryFromAttack) > 0) {
                return true; // Valid attack
            }
        }

    // If none of the adjacent territories are owned by the player
    cout << "You can only attack territories adjacent to the ones you own." << endl;
    return false;
}

int GameBoard::getDefenderId(int territoryToAttack) {
    return whosTerritory[territoryToAttack]-1;
}

int* GameBoard::armyCount(int territoryArmy) {
    int* arr = new int[3] {0}; // Dynamically allocate memory for the array and initialize all elements to 0
    for (list<Token>::iterator it = Territory[territoryArmy].begin(); it != Territory[territoryArmy].end(); ++it) {
        //cout << "**" << arr[0];
        if (it->getTroopValue() == 1) arr[0] += it->getTroopValue();
        //cout << "**" << arr[0];
        if (it->getTroopValue() == 5) arr[1] += it->getTroopValue();
        if (it->getTroopValue() == 10) arr[2] += it->getTroopValue();
        /*cout << "\n" << typeid(*it).name() << endl;
        if ((string)typeid(*it).name() == "class Infantry") {
            cout << "in typeid block\n";
            arr[0] += it->getTroopValue();

            cout << "**" << arr[0];
        }*/
        //if ((string)typeid(*it).name() == "class Cavalry") arr[1] += it->getTroopValue();
        //if ((string)typeid(*it).name() == "class Artillery") arr[2] += it->getTroopValue();
    }

    return arr;
}

int GameBoard::setAttackedArmy(int attacker, int defender, int aT, int dT) {
    whosTerritory[dT] = attacker;
    int* arr = armyCount(dT);
    int defenderReduce = 0;
    for (int i = 0; i < 3; i++) {
        defenderReduce += arr[i];
    }
    bool isPlaced = true;
    while(isPlaced){
    cout << "\nSelect the army you want to place in new territory" << endl;
    int zcount = 0;
    for (list<Token>::iterator it = Territory[aT].begin(); it != Territory[aT].end(); ++it) {

        if (it->getTroopValue() == 1) {
            cout << zcount + 1 << " is Infantry\n";
            zcount++;
        }

        if (it->getTroopValue() == 5) {
            cout << zcount + 1 << " is Cavalry\n";
            zcount++;
        }
        if (it->getTroopValue() == 10) {
            cout << zcount + 1 << " is Artillery\n";
            zcount++;
        }
    }
    int zchoice=0;
    cin >> zchoice;
    if (zchoice > zcount || zchoice<=0) {
        cout << "invalid.. try again..\n";
        continue;
    }
    else {
        Territory[dT].clear(); // Clear the list in dT territory
        list<Token>::iterator it = Territory[aT].begin();
        advance(it, zchoice - 1); // Move the iterator to the correct position
        Token tokenToMove = *it; // Save the token to move
        Territory[aT].erase(it); // Erase the token from aT territory
        Territory[dT].push_back(tokenToMove); // Push the token to dT territory
    }
    cout << "Do you want to move another army? \n1 or any = Yes \n2.No";
        int armyPlace;
        cin >> armyPlace;
        if (armyPlace == 2) {
            isPlaced = false;
        }
        else {
            continue;
        }
    }

    return defenderReduce;
}