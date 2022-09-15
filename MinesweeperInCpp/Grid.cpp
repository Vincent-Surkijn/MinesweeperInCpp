#include "Grid.h"

void Grid::print()
{
	std::cout << "Grid with mines at:";
	for (int i = 0; i < mineCoords.size(); ++i) {
		std::cout << mineCoords[i].x << "," << mineCoords[i].y << ";";
	}
	std::cout << "\n";
}
