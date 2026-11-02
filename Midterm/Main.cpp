
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

// Class 1: Represents one video game
class Game {
private:
    int id;
    string title;
    double rating;

public:
    Game() {
        id = 0;
        title = "";
        rating = 0;
    }

    Game(int gameId, string gameTitle, double gameRating) {
        id = gameId;
        title = gameTitle;
        rating = gameRating;
    }

    int getId() const {
        return id;
    }

    void display() const {
        cout << "ID: " << id
             << " | Title: " << title
             << " | Rating: " << rating << "/10" << endl;
    }

    void save(ofstream& file) const {
        file << id << " " << quoted(title)
             << " " << rating << endl;
    }
};

// Class 2: Manages the video game library
class GameLibrary {
private:
    static const int MAX_GAMES = 100;
    Game games[MAX_GAMES];  // Array of game records
    int count;

public:
    GameLibrary() {
        count = 0;
    }

    // Binary search requires sorted IDs
    int binarySearch(int target) const {
        int left = 0;
        int right = count - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (games[mid].getId() == target) {
                return mid;
            }

            if (games[mid].getId() < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;
    }

    void addGame(int id, string title, double rating) {
        if (count >= MAX_GAMES) {
            cout << "Library is full!" << endl;
            return;
        }

        if (id <= 0 || title.empty() ||
            rating < 0 || rating > 10) {
            cout << "Invalid game information!" << endl;
            return;
        }

        if (binarySearch(id) != -1) {
            cout << "That game ID already exists!" << endl;
            return;
        }

        // Insert game in sorted order by ID
        int position = count;

        while (position > 0 &&
               games[position - 1].getId() > id) {
            games[position] = games[position - 1];
            position--;
        }

        games[position] = Game(id, title, rating);
        count++;

        cout << "Game added successfully!" << endl;
    }

    void viewGames() const {
        cout << "\n=== ALL GAMES ===" << endl;

        if (count == 0) {
            cout << "No games in the library." << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            games[i].display();
        }
    }

    void searchGame(int id) const {
        int index = binarySearch(id);

        if (index == -1) {
            cout << "Game not found!" << endl;
        }
        else {
            cout << "Game found!" << endl;

            // Pointer to the matching game
            const Game* gamePtr = &games[index];
            gamePtr->display();
        }
    }

    void deleteGame(int id) {
        int index = binarySearch(id);

        if (index == -1) {
            cout << "Game not found!" << endl;
            return;
        }

        for (int i = index; i < count - 1; i++) {
            games[i] = games[i + 1];
        }

        count--;
        cout << "Game deleted successfully!" << endl;
    }

    void saveGames() const {
        ofstream file("games.txt");

        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            games[i].save(file);
        }

        file.close();
        cout << "Games saved to games.txt!" << endl;
    }

    void loadGames() {
        ifstream file("games.txt");

        if (!file) {
            cout << "No saved file found!" << endl;
            return;
        }

        // Read into a temporary library first
        GameLibrary loaded;
        int id;
        string title;
        double rating;

        while (file >> id >> quoted(title) >> rating) {
            if (id <= 0 || title.empty() ||
                rating < 0 || rating > 10 ||
                loaded.count >= MAX_GAMES ||
                loaded.binarySearch(id) != -1) {
                cout << "Invalid saved data!" << endl;
                return;
            }

            loaded.addGame(id, title, rating);
        }

        if (!file.eof()) {
            cout << "Error reading saved data!" << endl;
            return;
        }

        file.close();

        // Replace current records only after a valid load
        for (int i = 0; i < loaded.count; i++) {
            games[i] = loaded.games[i];
        }

        count = loaded.count;
        cout << "Games loaded successfully!" << endl;
    }

    void showDataSizes() const {
        cout << "\n=== DATA TYPE SIZES ===" << endl;
        cout << "int: " << sizeof(int) << " bytes" << endl;
        cout << "double: " << sizeof(double) << " bytes" << endl;
        cout << "string: " << sizeof(string) << " bytes" << endl;
        cout << "Game object: " << sizeof(Game) << " bytes" << endl;
        cout << "Game pointer: " << sizeof(Game*) << " bytes" << endl;
    }
};

// Read an integer safely
int readInt() {
    int value;

    while (!(cin >> value)) {
        cout << "Enter a valid whole number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

// Read a decimal number safely
double readDouble() {
    double value;

    while (!(cin >> value)) {
        cout << "Enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

int main() {
    GameLibrary library;
    int choice = 0;

    // Starting records
    library.addGame(101, "Dark Souls", 9.0);
    library.addGame(102, "Disco Elysium", 9.5);
    library.addGame(103, "Elden Ring", 9.2);

    while (choice != 8) {
        cout << "\n========== GAME LIBRARY ==========" << endl;
        cout << "1. Add a game" << endl;
        cout << "2. View all games" << endl;
        cout << "3. Search for a game" << endl;
        cout << "4. Delete a game" << endl;
        cout << "5. Save games to file" << endl;
        cout << "6. Load games from file" << endl;
        cout << "7. Show data type sizes" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";

        choice = readInt();

        if (choice == 1) {
            int id;
            string title;
            double rating;

            cout << "Enter game ID: ";
            id = readInt();

            cout << "Enter game title: ";
            getline(cin, title);

            cout << "Enter rating (0-10): ";
            rating = readDouble();

            library.addGame(id, title, rating);
        }
        else if (choice == 2) {
            library.viewGames();
        }
        else if (choice == 3) {
            cout << "Enter game ID to search: ";
            int id = readInt();
            library.searchGame(id);
        }
        else if (choice == 4) {
            cout << "Enter game ID to delete: ";
            int id = readInt();
            library.deleteGame(id);
        }
        else if (choice == 5) {
            library.saveGames();
        }
        else if (choice == 6) {
            library.loadGames();
        }
        else if (choice == 7) {
            library.showDataSizes();
        }
        else if (choice == 8) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid menu option!" << endl;
        }
    }

    return 0;
}
