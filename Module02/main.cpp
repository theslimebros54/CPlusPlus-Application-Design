#include <iostream>
#include <string>
#include <limits>
using namespace std;

void addGame() {
    cout << "\nAdd Game selected." << endl;
}

void viewGames() {
    cout << "\nView Games selected." << endl;
}

void searchGames() {
    cout << "\nSearch Games selected." << endl;
}

void updateGame() {
    cout << "\nUpdate Game selected." << endl;
}

void deleteGame() {
    cout << "\nDelete Game selected." << endl;
}

int main() {
    int choice = 0;

    while (choice != 6) {
        cout << "\n=== VIDEO GAME LIBRARY ===" << endl;
        cout << "1. Add Game" << endl;
        cout << "2. View Games" << endl;
        cout << "3. Search Games" << endl;
        cout << "4. Update Game" << endl;
        cout << "5. Delete Game" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";

        cin >> choice;

        // Checks if the user entered something that is not a number
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from 1 to 6." << endl;
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                addGame();
                break;

            case 2:
                viewGames();
                break;

            case 3:
                searchGames();
                break;

            case 4:
                updateGame();
                break;

            case 5:
                deleteGame();
                break;

            case 6:
                cout << "\nGoodbye!" << endl;
                break;

            default:
                cout << "\nInvalid choice. Please choose 1 through 6." << endl;
        }
    }

    return 0;
}
