// StatisticsKeeper.h
#ifndef STATISTICS_KEEPER_H
#define STATISTICS_KEEPER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class StatisticsKeeper {
public:
    StatisticsKeeper();
    ~StatisticsKeeper();
    void update_statistics(int numGames, int numPlayers, int attackCount, int gamesPlayed, string winnerName);

    void print_statistics();

private:
    int totalGamesPlayed;
    int averagePlayersPerGame;
    int maxPlayersPerGame;
    int minPlayersPerGame;
    int numPlayersCount=0;
    int maxAttackCount;
    int minAttackCount=0;
    int statAttackCount = 0;
    std::map<std::string, int> winningFrequencyByName;

    // Helper function to calculate average players per game
    void calculate_average_players_per_game(int numPlayer, int gamePlayed);
};

#endif // STATISTICS_KEEPER_H
