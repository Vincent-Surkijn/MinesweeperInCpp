
#include <iostream>
#include "Grid.h"

int main()
{
    std::cout << "Welcome to this C++ minesweeper!\n";
    Grid g = Grid(Level::HARD);

    std::cout << "Grid print:\n";
    g.print();

    /*
    int dims[2];
    g.getGridSize(dims);
    std::cout << "Grid dims:" << dims[0] << "," << dims[1] << "\n";

    std::vector<coord> v = g.getMineCoords();
    std::cout << "First coord:" << v[0].x << "," << v[0].y << "\n";


    std::vector<std::vector<int>>	field{
        {1,2,3},
        {4,5,6}
    };
    std::cout << "V length test:" << field.size() << "\n";
    std::cout << "V index test:" << field[1][2] << "\n";

    Tile t = Tile(coord{1,2});
    std::cout << "Tile c test:" << t.getCoords().x << "," << t.getCoords().y << "\n";
    */
}