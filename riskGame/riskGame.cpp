//riskGame main file

#include <iostream>
#include "RiskGameSimulator.h"
using namespace std; 

int main()
{
    StatisticsKeeper statsKeeper;
			RiskGameSimulator myGame1;
			myGame1.get_user_input();
			for (int i = 0; i < myGame1.numGames; i++) {
				myGame1.playMultipleGames();
                
			}
			
			cout << "printing directly from main and check if it is exiting from play multiple games method" << endl;
			myGame1.printResult(); 

	return 0;
}
