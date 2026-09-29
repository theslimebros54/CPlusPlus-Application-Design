#include <iostream>
#include "GameTools.h"
using namespace std;

void addGame()
{
    cout << "Game added successfully!" << endl;
}

void displayGames()
{
    cout << "=== GAME RECORDS ===" << endl;
    cout << "Wii Sports - 2006" << endl;
    cout << "Super Mario Bros. - 1985" << endl;
    cout << "Mario Kart Wii - 2008" << endl;
}

void calculateAverage()
{
    double scores[3] = { 8.5, 9.0, 9.5 };
    double average = (scores[0] + scores[1] + scores[2]) / 3;

    cout << "Average game rating: " << average << endl;
}
