//Player header file
#include <iostream>
#include <set>
#include <string>
#include <list>
#include <fstream>
#include "Token.h"
#include "Dice.h"

using namespace std; 

class Player
{
	string name;
	string color;
	int playerID;
	int numOfTerritories;
	int troopStrength;
	int tokenValue[3] = { 15, 3, 2 };
	set <int> territory = {};
	multiset <int> diceresult;
	Token* tokens[3];
	Dice dice; 

public: 
	Player(); // Default constructor
	Player(const string& name, string& color, int playerID);
	~Player(); // Destructor
	void displayInfo() const;
	void setColor(const string& col); // Method to set player's color
	void incrementTerritory(int occupied);
	void decrementTerritory(int territoryAttacked, int defenderTroopDecrease);
	string getName();
	list<Token> placeArmy(int choice);
	void move();
	void roll();
	void setUser(const string& name, string& color, int playerID);
	set <int> getTerritories();
	int* getDiceResult();
};

