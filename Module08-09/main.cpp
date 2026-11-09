
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

struct Game {
    int id;
    string title;
    double rating;
    string genre;
};

// Safely read a whole number
int getNumber(string message, int minimum, int maximum) {
    int number;

    while (true) {
        cout << message;

        if (cin >> number && number >= minimum && number <= maximum) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }

        cout << "Invalid entry. Enter a number between "
             << minimum << " and " << maximum << ".\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Safely read a rating
double getRating() {
    double rating;

    while (true) {
        cout << "Enter rating (0-10): ";

        if (cin >> rating && rating >= 0 && rating <= 10) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return rating;
        }

        cout << "Invalid rating. Enter a number from 0 to 10.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Prevent empty game titles
string getTitle() {
    string title;

    while (true) {
        cout << "Enter game title: ";
        getline(cin, title);

        if (title.find_first_not_of(" \t") != string::npos) {
            return title;
        }

        cout << "Title cannot be empty. Try again.\n";
    }
}

// Add a game with validation
void addGame(vector<Game>& games) {
    int id = getNumber("Enter game ID (1-9999): ", 1, 9999);

    for (const Game& game : games) {
        if (game.id == id) {
            cout << "Error: Game ID already exists.\n";
            return;
        }
    }

    string title = getTitle();
    double rating = getRating();

    cout << "Choose genre:\n";
    cout << "1. RPG\n2. Action\n3. Strategy\n";

    int genreChoice = getNumber("Genre: ", 1, 3);

    string genre;

    if (genreChoice == 1)
        genre = "RPG";
    else if (genreChoice == 2)
        genre = "Action";
    else
        genre = "Strategy";

    games.push_back({id, title, rating, genre});

    cout << "Game added successfully!\n";
}

// Display game records
void viewGames(const vector<Game>& games) {
    cout << "\n=== GAME LIBRARY ===\n";

    for (const Game& game : games) {
        cout << "ID: " << game.id
             << " | " << game.title
             << " | Rating: " << game.rating
             << " | Genre: " << game.genre << endl;
    }
}

// Module 9: Mock AI recommendation prototype
void aiRecommendation(const vector<Game>& games) {
    cout << "\n=== AI GAME RECOMMENDATION (MOCK) ===\n";
    cout << "What genre do you enjoy?\n";
    cout << "1. RPG\n2. Action\n3. Strategy\n";

    int choice = getNumber("Choose genre: ", 1, 3);

    string preferredGenre;

    if (choice == 1)
        preferredGenre = "RPG";
    else if (choice == 2)
        preferredGenre = "Action";
    else
        preferredGenre = "Strategy";

    // Simulates an AI choosing the highest-rated match
    const Game* bestGame = nullptr;

    for (const Game& game : games) {
        if (game.genre == preferredGenre) {
            if (bestGame == nullptr || game.rating > bestGame->rating) {
                bestGame = &game;
            }
        }
    }

    if (bestGame != nullptr) {
        cout << "\nMock AI recommendation: "
             << bestGame->title << endl;
        cout << "Reason: This is the highest-rated "
             << preferredGenre << " game in your library.\n";
    }
    else {
        cout << "No games match that genre.\n";
    }

    cout << "(Prototype only - no real AI service connected.)\n";
}

int main() {
    vector<Game> games = {
        {101, "Dark Souls", 9.0, "RPG"},
        {102, "Disco Elysium", 9.5, "RPG"},
        {103, "Elden Ring", 9.2, "Action"}
    };

    int choice;

    do {
        cout << "\n========== GAME LIBRARY ==========\n";
        cout << "1. Add a game\n";
        cout << "2. View games\n";
        cout << "3. Mock AI recommendation\n";
        cout << "4. Exit\n";

        choice = getNumber("Enter your choice: ", 1, 4);

        if (choice == 1)
            addGame(games);
        else if (choice == 2)
            viewGames(games);
        else if (choice == 3)
            aiRecommendation(games);

    } while (choice != 4);

    cout << "Goodbye!\n";
    return 0;
}
