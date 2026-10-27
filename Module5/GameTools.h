
#ifndef GAMETOOLS_H
#define GAMETOOLS_H

#include <string>
#include <vector>
using namespace std;

struct Game {
    string title;
    double rating;
};

void addGame(vector<Game>& games, string title, double rating);
void displayGames(const vector<Game>& games);
void calculateAverage(const vector<Game>& games);

#endif
