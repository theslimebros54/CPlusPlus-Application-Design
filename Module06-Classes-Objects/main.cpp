#include <iostream>
#include <string>
using namespace std;

class Game
{
private:
    string title;
    int releaseYear;
    double rating;

public:
    // Constructor
    Game(string gameTitle, int year, double gameRating)
    {
        title = gameTitle;
        releaseYear = year;
        rating = gameRating;
    }

    // Member function 1
    void displayGame()
    {
        cout << "Title: " << title << endl;
        cout << "Release Year: " << releaseYear << endl;
        cout << "Rating: " << rating << endl;
    }

    // Member function 2
    void updateRating(double newRating)
    {
        rating = newRating;
    }

    // Getter
    string getTitle()
    {
        return title;
    }
};

int main()
{
    // Create two Game objects
    Game game1("Dark Souls", 2011, 9.0);
    Game game2("Disco Elysium", 2019, 9.5);

    cout << "=== VIDEO GAME LIBRARY ===" << endl;

    game1.displayGame();

    cout << endl;

    game2.displayGame();

    return 0;
}
