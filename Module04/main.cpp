#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Video game data from Kaggle
    string names[5] = {
        "Wii Sports",
        "Super Mario Bros.",
        "Mario Kart Wii",
        "Wii Sports Resort",
        "Pokemon Red/Pokemon Blue"
    };

    int years[5] = {
        2006,
        1985,
        2008,
        2009,
        1996
    };

    double globalSales[5] = {
        82.74,
        40.24,
        35.82,
        33.00,
        31.37
    };

    // Pointer to the first sales value
    double* salesPtr = &globalSales[0];

    cout << "=== VIDEO GAME SALES ===" << endl;

    // Display all 5 records
    for (int i = 0; i < 5; i++)
    {
        cout << names[i]
             << " | Year: " << years[i]
             << " | Global Sales: " << globalSales[i]
             << " million" << endl;
    }

    // Access a value through a pointer
    cout << endl;
    cout << "First game's sales through pointer: "
         << *salesPtr << " million" << endl;

    return 0;
}
