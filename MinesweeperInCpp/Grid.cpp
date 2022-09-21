#include "Grid.h"

void Grid::generateMineCoords() {
	// Retrieve dimensions ([row,column]) for this level
	int dims[2];
	this->getGridSize(dims);
	// Generate unique mine coordinates
	for (int i = 0; i < this->getNumberOfMines(); ++i) {
		coord c;
		do {
			c = coord{ randInt(0,dims[0] - 1), randInt(0,dims[1] - 1) };
		} while (this->coordIsMine(c));
		mineCoords.push_back(c);
	}
}

void Grid::populateField() {
	// Retrieve dimensions for this level
	int dims[2];
	this->getGridSize(dims);
	for (int r = 0; r < dims[0]; ++r) {	// Loop through rows
		// Initialize temp vector
		std::vector<Tile*> v;
		for (int c = 0; c < dims[1]; ++c) {	// Loop through columns
			// Check if it should be a normal Tile or a Mine
			if (this->coordIsMine(coord{ r, c })) {
				Mine m = Mine(coord{ r, c });
				Mine* mPtr = new(Mine);
				*mPtr = m;
#ifdef DEBUG
				//(*mPtr).setClicked(true);
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
				//(*tPtr).setClicked(true);
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
		std::cout << mineCoords[i] << ";";
	}
	std::cout << "\n";
#endif
	int dims[2];
	// Store grid size in dims variable
	getGridSize(dims);
	// Print grid field
	// Loop through rows
	for (int r = 0; r < dims[0] + 1; ++r) {
		// Print row numbers in correct format
		if (r == 0) {
			std::cout << "  ";
		}
		else if (r - 1 < 10) {
			std::cout << r - 1 << " ";
		}
		else {
			std::cout << r - 1;
		}
		// Loop through columns
		for (int c = 0; c < dims[1]; ++c) {
			// Print column numbers
			if (r == 0) {
				std::cout << " " << c;
				// Print an extra space for numbers under 10
				if (c < 10) std::cout << " ";
				continue;
			}
			// Print tiles
			Tile* t = field[r-1][c];
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
	// Get row and column number
	int row = c.row;
	int col = c.col;
	// Store coordinates of all neighbors
	coord neighbors[8]{
		coord{row-1, col-1},
		coord{row-1, col},
		coord{row-1, col-1},
		coord{row, col-1},
		coord{row+1,col-1},
		coord{row+1,col},
		coord{row+1,col+1},
		coord{row,col+1}
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

// TODO: continue working on this function
int Grid::receiveUserInput(UserInput input) {
	// First check which action was inputted
	if (input.act == 'f') {	// Action = flagging
		// Check if maximum amount of flags (= amount of mines) has been reached
		if (flagsSet == this->getNumberOfMines()) {
			std::cout << "Maximum amount of flags has been reached!\n";
			// Game continues
			return 0;
		}
		// Retrieve selected Tile
		Tile* t = this->getTileAtCoord(input.c);
		// Check its previous flagged state
		if (t->getFlagged()) {	// Was already flagged
			// Update state
			t->setFlagged(false);
			// Decrement counter
			--this->flagsSet;
		}
		else {
			// Update state
			t->setFlagged(true);
			// Increment counter
			++this->flagsSet;
		}
		// Game continues
		return 0;
	}
	else {	// Action = clicking
		// Retrieve selected Tile
		Tile* t = this->getTileAtCoord(input.c);
		// Check its previous state
		if (t->getClicked()) {	// Was already clicked
			std::cout << "Tile at " << input.c << " was already clicked!\n";
			// Game continues
			return 0;
		}
		if (t->isMine()) {	// Clicked a mine
			// Game is lost
			return 2;
		}
	}
}