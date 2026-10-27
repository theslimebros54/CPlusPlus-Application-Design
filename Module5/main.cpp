
#include <iostream>
#include <vector>
#include "GameTools.h"
using namespace std;

int main()
{
    vector<Game> games;

    cout << "=== VIDEO GAME LIBRARY ===" << endl;

    // Actually add game records
    addGame(games, "Dark Souls", 9.0);
    addGame(games, "Disco Elysium", 9.5);
    addGame(games, "Elden Ring", 9.2);

    // Display the saved records
    displayGames(games);

    // Calculate the average rating
    calculateAverage(games);

    return 0;
}
