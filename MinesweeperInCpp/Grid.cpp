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
	for (int c = 0; c < dims[0]; ++c) {	// Loop through rows
		for (int r = 0; r < dims[1]; ++r) {
			//std::cout << "Field in print:" << &field << "\n";
			Tile* t = field[r][c];
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
