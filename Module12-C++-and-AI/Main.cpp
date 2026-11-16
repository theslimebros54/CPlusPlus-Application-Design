
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Search through records one at a time
int linearSearch(const vector<int>& ids, int target) {
    for (int i = 0; i < ids.size(); i++) {
        if (ids[i] == target) {
            return i;
        }
    }
    return -1;
}

// Search sorted records by repeatedly dividing the range
int binarySearch(const vector<int>& ids, int target) {
    int left = 0;
    int right = static_cast<int>(ids.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (ids[mid] == target) {
            return mid;
        }
        else if (ids[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> gameIds;

    // Simulate a large library with 100,000 games
    for (int i = 1; i <= 100000; i++) {
        gameIds.push_back(i);
    }

    int target = 99999;
    const int repetitions = 1000;

    // Time linear search
    auto start = chrono::steady_clock::now();

    int linearResult = -1;
    for (int i = 0; i < repetitions; i++) {
        linearResult = linearSearch(gameIds, target);
    }

    auto end = chrono::steady_clock::now();

    auto linearTime =
        chrono::duration_cast<chrono::microseconds>(
            end - start).count();

    // Time binary search
    start = chrono::steady_clock::now();

    int binaryResult = -1;
    for (int i = 0; i < repetitions; i++) {
        binaryResult = binarySearch(gameIds, target);
    }

    end = chrono::steady_clock::now();

    auto binaryTime =
        chrono::duration_cast<chrono::microseconds>(
            end - start).count();

    cout << "=== GAME LIBRARY PERFORMANCE TEST ===\n";
    cout << "Total game IDs: " << gameIds.size() << endl;
    cout << "Searching for game ID: " << target << endl;

    cout << "\nLinear search result: "
         << linearResult << endl;
    cout << "Linear search time: "
         << linearTime << " microseconds\n";

    cout << "\nBinary search result: "
         << binaryResult << endl;
    cout << "Binary search time: "
         << binaryTime << " microseconds\n";

    cout << "\nBinary search is useful for finding "
         << "records in large sorted datasets.\n";

    return 0;
}
