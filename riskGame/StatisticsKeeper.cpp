// StatisticsKeeper.cpp
#include "StatisticsKeeper.h"

StatisticsKeeper::StatisticsKeeper() : totalGamesPlayed(0), averagePlayersPerGame(0), maxPlayersPerGame(0), minPlayersPerGame(0), maxAttackCount(0){}

StatisticsKeeper::~StatisticsKeeper() {}

void StatisticsKeeper::update_statistics(int numGames, int numPlayers, int attackCount, int gamesPlayed, string winnerName) {
	if(totalGamesPlayed!=numGames)
		totalGamesPlayed = numGames;

	if (maxPlayersPerGame < numPlayers) {
		maxPlayersPerGame = numPlayers;
	}

	if (maxAttackCount < attackCount) {
		maxAttackCount = attackCount;
	}

	if (minPlayersPerGame == 0 || minPlayersPerGame > numPlayers) {
		minPlayersPerGame = numPlayers;
	}
	if (minAttackCount == 0 || minAttackCount > attackCount) {
		minAttackCount = attackCount;
	}

	statAttackCount += attackCount;
	numPlayersCount += numPlayers;
	this->calculate_average_players_per_game(numPlayersCount, gamesPlayed+1);

	if (winningFrequencyByName.find(winnerName) != winningFrequencyByName.end()) {
		winningFrequencyByName[winnerName]++;
	}
	else {
		winningFrequencyByName[winnerName] = 1;
	}
	cout << "Printing all from statistics: \nnumPlauuyers: " << numPlayers << "attackCount: " << attackCount <<
		"gamesPlayed: " << gamesPlayed+1 << "winnerName: " << winnerName << endl;
}

void StatisticsKeeper::print_statistics() {
	
	cout << "Printing statistics to file..." << endl; 

	// Open the file for appending
	std::ofstream outfile("output.txt", std::ios::app);

	// Check if the file is opened successfully
	if (outfile.is_open()) {
		// Write to the file
		outfile << "Game Statistics\n";
		outfile << "----------------\n";
		outfile << "Total number of games played: " << totalGamesPlayed << std::endl;
		outfile << "Total number of players generated: " << averagePlayersPerGame << std::endl;
		outfile << "Maximum number of players generated for a game: " << maxPlayersPerGame << std::endl;
		outfile << "Minimum number of players generated for a game: " << minPlayersPerGame << std::endl;
		outfile << "Average number of players generated for a game: " << averagePlayersPerGame << std::endl;
		outfile << "Winning Frequency: \n";
		for (const auto& pair : winningFrequencyByName) {
			outfile << "Name: " << pair.first << ", Winning Count: " << pair.second << std::endl;
		}
		outfile << "Maximum number of rounds played in a game: " << maxAttackCount << std::endl;
		outfile << "Minimum number of rounds played in a game: " << minAttackCount << std::endl;
		outfile << "Average number of rounds played in a game: " << statAttackCount / totalGamesPlayed << std::endl;

		outfile << "\n\n";
		// Close the file
		outfile.close();
		std::cout << "Data appended to the file successfully.\n";
	}
	else {
		// Print an error message if the file couldn't be opened
		std::cerr << "Error opening file for appending!\n";
	}



}

void StatisticsKeeper::calculate_average_players_per_game(int numPlayer, int gamePlayed) {
	averagePlayersPerGame = numPlayer / gamePlayed;
}

