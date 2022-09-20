
#include <iostream>
#include <string>
#include "Grid.h"


// Forward declarations of main methods
void getInput(Grid& g);

int main()
{
    std::cout << "Welcome to this C++ minesweeper!\n";
    std::cout << "Pick a level: Easy (0)\n";
    std::cout << "              Medium (1)\n";
    std::cout << "              Hard (2)\n";

    int level = 0;
    do {
        std::cout << "Enter the level:";
        std::cin >> level;
    } while (level < 0 || level >= static_cast<int>(Level::MAX));

    Grid g = Grid(static_cast<Level>(level));

    while (true) {
        // Print the field
        g.print();

        // Retrieve user input
        getInput(g);
    }

}


// TODO: continue working on this function
void getInput(Grid& g) {
#ifdef DEBUG
    std::cout << "Entering getInput\n";
#endif // DEBUG
    // Init input vars
    char act;
    int x;
    int y;
    // Init test var
    bool test;
    do {
        // Retrieve the action
        std::cout << "Enter an action(F=flag,C=click):";
        std::cin >> act;
        // Retrieve the x coord
        std::cout << "Enter a x coordinate:";
        std::cin >> x;
        // Retrieve the y coord
        std::cout << "Enter a y coordinate:";
        std::cin >> y;
        // Retrieve grid dimensions for checking input coordinates
        int dims[2];
        g.getGridSize(dims);
        // Test if inputted number and char are valid
        bool numTest = x > 0 && y > 0 && x < dims[0] && y < dims[1];
        bool charTest = std::tolower(act) == 'c' || std::tolower(act) == 'f';
        // Ask input again if one of the tests doesn't pass
        test = !(numTest && charTest);
    } while (test);
}