
#include <iostream>
#include "GameTools.h"
using namespace std;

void addGame(vector<Game>& games, string title, double rating)
{
    Game newGame;
    newGame.title = title;
    newGame.rating = rating;

    games.push_back(newGame);

    cout << title << " added successfully!" << endl;
}

void displayGames(const vector<Game>& games)
{
    cout << "\n=== GAME RECORDS ===" << endl;

    if (games.empty()) {
        cout << "No games available." << endl;
        return;
    }

    for (int i = 0; i < games.size(); i++) {
        cout << games[i].title
             << " | Rating: " << games[i].rating << endl;
    }
}

void calculateAverage(const vector<Game>& games)
{
    if (games.empty()) {
        cout << "No ratings to calculate." << endl;
        return;
    }

    double total = 0;

    for (int i = 0; i < games.size(); i++) {
        total += games[i].rating;
    }

    double average = total / games.size();

    cout << "\nAverage game rating: "
         << average << endl;
}
