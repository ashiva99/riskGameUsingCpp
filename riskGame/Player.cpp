//Player cpp file
#include <set>
#include "Player.h"

Player::Player() : name(""), color(""), playerID(0), numOfTerritories(0), troopStrength(0), dice() {}

Player::Player(const string& name, string& color, int playerID)
    : name(name), color(color), playerID(playerID), numOfTerritories(0), troopStrength(0) {}



Player::~Player() {
    // Release memory for tokens array
    for (int i = 0; i < 3; ++i) {
        delete tokens[i];
    }
}

void Player::displayInfo() const {
    cout << "Player Name: " << name << endl;
    cout << "Player Color: " << color << endl;
    cout << "Player ID: " << playerID << endl;
    cout << "Number of Territories: " << numOfTerritories << endl;
    cout << "Troop Strength: " << troopStrength <<"\n"<< endl;

    // Open a file for writing in append mode
    std::ofstream outfile("playerInfo.txt", std::ios::app);

    // Check if the file is opened successfully
    if (outfile.is_open()) {
        // Write to the file
        outfile << "Player Name: " << name << std::endl;
        outfile << "Player Color: " << color << std::endl;
        outfile << "Player ID: " << playerID << std::endl;
        outfile << "Number of Territories: " << numOfTerritories << std::endl;
        outfile << "Troop Strength: " << troopStrength << std::endl;
        outfile << "\n\n";
        // Close the file
        outfile.close();
        //std::cout << "Data appended to the file successfully.\n";
    }
    else {
        // Print an error message if the file couldn't be opened
        std::cerr << "Error opening file for appending!\n";
    }
}
void Player::setColor(const string& col) {
    color = col;
}

void Player::incrementTerritory(int occupied) {
    territory.insert(occupied);
    ++numOfTerritories;
}

void Player::decrementTerritory(int territoryAttacked, int defenderTroopDecrease) {
    --numOfTerritories;
    territory.erase(territory.find(territoryAttacked));
    troopStrength -= defenderTroopDecrease;
}

string Player::getName() {
    return name;
}



list<Token> Player::placeArmy(int choice) {
    territory.insert(choice); //
    numOfTerritories = int(territory.size());
    list<Token> tokenlist;

    if (tokenValue[0] == 0 && tokenValue[1] == 0 && tokenValue[2] == 0) {
        cout << "Token value exhausted" << endl;
        return {};
    }
    bool tokenexit = false;
    while (!tokenexit) {
        cout << "Choose the Token you want to insert \n 1.Infantry:"<< tokenValue[0] << "\n 2.Cavalry:"<< tokenValue[1] <<"\n 3.Artillery:"<< tokenValue[2] << endl;
        int choice; 
        cin >> choice; 
        
        switch (choice) {
            case 1: 
                if (tokenValue[choice-1] != 0) {
                    cout << "how many Infantrys you want to insert: ";
                    int i;
                    cin >> i;
                    if(tokenValue[choice-1]>=i){
                        for (int j = 0; j < i; ++j) {
                            Infantry infantry;
                            tokenlist.push_back(infantry);
                            troopStrength += infantry.getTroopValue();
                            tokenValue[choice-1]--;
                        }
                    }
                    else {
                        cout << "given choice is greater then available...\n try again..." << endl;
                        continue;
                    }
                }
                break;
            case 2:
                if (tokenValue[choice-1] != 0) {
                    cout << "how many Cavalry you want to insert: ";
                    int i;
                    cin >> i;
                    if (tokenValue[choice-1] >= i) {
                        for (int j = 0; j < i; ++j) {
                            Cavalry cavalry;
                            tokenlist.push_back(cavalry);
                            troopStrength += cavalry.getTroopValue();
                            tokenValue[choice-1]--;
                        }
                    }
                    else {
                        cout << "given choice is greater then available...\n try again..." << endl;
                        continue;
                    }
                }
                break;
            case 3:
                if (tokenValue[choice - 1] != 0) {
                    cout << "how many Artillery you want to insert: ";
                    int i;
                    cin >> i;
                    if (tokenValue[choice - 1] >= i) {
                        for (int j = 0; j < i; ++j) {
                            Artillery artillery;
                            tokenlist.push_back(artillery);
                            troopStrength += artillery.getTroopValue();
                            tokenValue[choice - 1]--;
                        }
                    }
                    else {
                        cout << "given choice is greater then available...\n try again..." << endl;
                        continue;
                    }
                }
                break;
            default:
                cout << "Invalid selection..\nTry again...";
                continue;
        }
        cout << "do you want to continue token insertion? 1.Yes \n 2.No" << endl;
        int i;
        cin >> i;
        if (i == 2) {
            tokenexit = true;
        }
    }
    return tokenlist;
 }
    

void Player::move() {
    cout << "game ended" << endl;
}

void Player::roll() {
    for (int i = 0; i < 3; i++) {
        int rollResult = dice.roll();
        diceresult.insert(rollResult); // Roll the dice
        //cout << "printing from player roll roll: " << rollResult << endl; 
    }
}
void Player::setUser(const string& name, string& color, int playerID) {
    this->name = name;
    this->color = color;
    this->playerID = playerID;
}

set <int> Player::getTerritories() {
    return territory; // Roll the dice
}

int* Player::getDiceResult() {
    int* arr = new int[3];
    int i = 0;
    for (auto& it : diceresult) {
        arr[i] = it;
        //cout << "printing for reference purpose: array: " << arr[i] << " iterator: " << it << endl;
        i++;
    }
    return arr;
}