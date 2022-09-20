#include "Grid.h"

bool operator==(coord& c1, coord& c2) {
	return c1.x == c2.x && c1.y == c2.y;
}

void Grid::generateMineCoords() {
	// Retrieve dimensions for this level
	int dims[2];
	this->getGridSize(dims);
	// Generate unique mine coordinates
	for (int i = 0; i < this->getNumberOfMines(); ++i) {
		coord c;
		do {
			c = coord{ randInt(0,dims[0] - 1), randInt(0,dims[0] - 1) };
		} while (this->coordIsMine(c));
		mineCoords.push_back(c);
	}
}

void Grid::populateField() {
	// Retrieve dimensions for this level
	int dims[2];
	this->getGridSize(dims);
	for (int c = 0; c < dims[1]; ++c) {	// Loop through columns
		// Initialize temp vector
		std::vector<Tile*> v;
		for (int r = 0; r < dims[0]; ++r) {	// Loop through rows
			// Check if it should be a normal Tile or a Mine
			if (this->coordIsMine(coord{ r, c })) {
				Mine m = Mine(coord{ r, c });
				Mine* mPtr = new(Mine);
				*mPtr = m;
#ifdef DEBUG
				(*mPtr).setClicked(true);
				v.push_back(mPtr);
				std::cout << "Added mine at:" << r << "," << c << "\n";
				continue;
#endif
				// TODO: delete this memory
				v.push_back(mPtr);
			}
			else {
				Tile t = Tile(coord{ r, c });
				Tile* tPtr = new(Tile);
				*tPtr = t;
#ifdef DEBUG
				(*tPtr).setClicked(true);
				v.push_back(tPtr);
				continue;
#endif
				// TODO: delete this memory
				v.push_back(tPtr);
			}
		}
		field.push_back(v);
	}
}


void Grid::print(){
#ifdef DEBUG
	std::cout << "Grid with mines at:";
	for (int i = 0; i < mineCoords.size(); ++i) {
		std::cout << mineCoords[i].x << "," << mineCoords[i].y << ";";
	}
	std::cout << "\n";
#endif
	int dims[2];
	// Store grid size in dims variable
	getGridSize(dims);
	// Print grid field
	// Loop through rows
	for (int c = 0; c < dims[0] + 1; ++c) {
		// Print row numbers in correct format
		if (c == 0) {
			std::cout << "  ";
		}
		else if (c - 1 < 10) {
			std::cout << c - 1 << " ";
		}
		else {
			std::cout << c - 1;
		}
		// Loop through columns
		for (int r = 0; r < dims[1]; ++r) {
			// Print column numbers
			if (c == 0) {
				std::cout << " " << r;
				// Print an extra space for numbers under 10
				if (r < 10) std::cout << " ";
				continue;
			}
			// Print tiles
			Tile* t = field[r][c-1];
			(*t).print();
		}
		// Start a new line for the new row
		std::cout << "\n";
	}
}

bool Grid::coordIsMine(coord c){
	for (int i = 0; i < mineCoords.size(); ++i) {
		if (c == mineCoords[i])	return true;
	}
	return false;
}

int Grid::countNeighboringMines(coord c) {
	// Get x and y coordinate
	int x = c.x;
	int y = c.y;
	// Store coordinates of all neighbors
	coord neighbors[8]{
		coord{x-1, y-1},
		coord{x-1, y},
		coord{x-1, y-1},
		coord{x, y-1},
		coord{x+1,y-1},
		coord{x+1,y},
		coord{x+1,y+1},
		coord{x,y+1}
	};
	// Count how many neighbors are mines
	int count = 0;
	for (int i = 0; i < std::size(neighbors); ++i) {
		if (this->coordIsMine(neighbors[i])) {
			++count;
		}
	}
	// Return count
	return count;
}