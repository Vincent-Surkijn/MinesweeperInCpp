// MinesweeperInCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Grid.h"

int main()
{
    std::cout << "Welcome to this C++ minesweeper!\n";
    Grid g = Grid();
    g.print();
}