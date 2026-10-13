
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Game record
struct Game {
    int id;
    string title;
};

// Base User class
class User {
protected:
    string username;

public:
    User(string name) : username(name) {}

    void viewRecords(const vector<Game>& games) {
        cout << "\n=== VIDEO GAME LIBRARY ===" << endl;

        for (const Game& game : games) {
            cout << "ID: " << game.id
                 << " | Title: " << game.title << endl;
        }
    }
};

// Admin can add and delete games
class Admin : public User {
public:
    Admin(string name) : User(name) {}

    void addRecord(vector<Game>& games, int id, string title) {
        for (const Game& game : games) {
            if (game.id == id) {
                cout << "Game ID already exists!" << endl;
                return;
            }
        }

        games.push_back({id, title});

        sort(games.begin(), games.end(),
            [](const Game& a, const Game& b) {
                return a.id < b.id;
            });

        cout << "Game added successfully!" << endl;
    }

    void deleteRecord(vector<Game>& games, int id) {
        for (int i = 0; i < games.size(); i++) {
            if (games[i].id == id) {
                games.erase(games.begin() + i);
                cout << "Game deleted successfully!" << endl;
                return;
            }
        }

        cout << "Game not found!" << endl;
    }
};

// Regular users can only view games
class RegularUser : public User {
public:
    RegularUser(string name) : User(name) {}
};

// Binary search by game ID
int binarySearch(const vector<Game>& games, int target) {
    int left = 0;
    int right = static_cast<int>(games.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (games[mid].id == target)
            return mid;

        if (games[mid].id < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    vector<Game> games = {
        {101, "Dark Souls"},
        {102, "Disco Elysium"},
        {103, "Elden Ring"}
    };

    Admin admin("Admin");
    RegularUser player("Player");

    // Admin actions
    cout << "=== ADMIN ===" << endl;
    admin.viewRecords(games);
    admin.addRecord(games, 104, "Hollow Knight");
    admin.deleteRecord(games, 101);

    // Regular User actions
    cout << "\n=== REGULAR USER ===" << endl;
    player.viewRecords(games);

    // Binary search
    cout << "\n=== SEARCH ===" << endl;

    int target = 103;
    int result = binarySearch(games, target);

    if (result != -1) {
        cout << "Game found: "
             << games[result].title << endl;
    }
    else {
        cout << "Game not found!" << endl;
    }

    return 0;
}
