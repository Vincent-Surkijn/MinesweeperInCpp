
#include <iostream>
#include <string>
#include "Grid.h"


// Forward declarations of main methods
UserInput getInput(Grid& g);

int main()
{
    // Print info
    std::cout << "Welcome to this C++ minesweeper!\n";
    std::cout << "Pick a level: Easy (0)\n";
    std::cout << "              Medium (1)\n";
    std::cout << "              Hard (2)\n";

    // Init var to store input
    int level{ 0 };
    // Retrieve difficulty level
    do {
        std::cout << "Enter the level:";
        std::cin >> level;
    } while (level < 0 || level >= static_cast<int>(Level::MAX));

    // Init grid
    Grid g = Grid(static_cast<Level>(level));

    // Init loop var
    int res{ 0 };
    do {
#ifndef DEBUG
        // Print the field
        g.print();
#endif // !DEBUG
#ifdef DEBUG
        // Print the field
        g.print(true);
#endif // DEBUG



        // Retrieve user input
        UserInput input = getInput(g);
#ifdef DEBUG
        std::cout << "Returned input:";
        std::cout << input;
        std::cout << "\n";
#endif // DEBUG

        // Pass input to grid
        res = g.receiveUserInput(input);

    } while (!res);   // res will be zero as long as game continues

    // Determine what final message to print
    if (res == 1) {
        std::cout << "Congrats! You won!\n";
    }
    else if (res == 2) {
        std::cout << "Unfortunately, you exploded :'(\n";
    }
    else {
        std::cout << "How the hell did this happen???\n";
    }
    // Game over
}


// Main methods implementations
UserInput getInput(Grid& g) {
#ifdef DEBUG
    std::cout << "Entering getInput\n";
#endif // DEBUG
    // Init input vars
    char act;
    int r;
    int c;
    // Init test var
    bool test;
    do {
        // Retrieve the action
        std::cout << "Enter an action(F = set/undo flag, C = click):";
        std::cin >> act;
        act = std::tolower(act);
        // Retrieve the x coord
        std::cout << "Enter a row number:";
        std::cin >> r;
        // Retrieve the y coord
        std::cout << "Enter a column:";
        std::cin >> c;
        // Retrieve grid dimensions for checking input coordinates
        int dims[2];
        g.getGridSize(dims);
        // Test if inputted number and char are valid
        bool numTest = r >= 0 && c >= 0 && r < dims[0] && c < dims[1];
        bool charTest = act == 'c' || act == 'f';
        // Ask input again if one of the tests doesn't pass
        test = !(numTest && charTest);
    } while (test);
    // Return struct with inputted values
    return UserInput{ act, r, c };
}