#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Variables for a video game
    string gameName = "Helldivers 2";
    int releaseYear = 2024;
    double price = 39.99;
    float rating = 8.5f;
    char ageRating = 'M';
    bool multiplayer = true;

    cout << "=== VIDEO GAME LIBRARY ===" << endl;

    cout << "Game Name: " << gameName << endl;
    cout << "Release Year: " << releaseYear << endl;
    cout << "Price: $" << price << endl;
    cout << "Rating: " << rating << endl;
    cout << "Age Rating: " << ageRating << endl;
    cout << "Multiplayer: " << multiplayer << endl;

    return 0;
}
