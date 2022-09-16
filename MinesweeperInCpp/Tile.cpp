
#include "Tile.h"

// Setters
void Tile::setClicked(bool clicked) {
	this->clicked = clicked;
}

void Tile::setFlagged(bool flagged) {
	this->flagged = flagged;
}

// Other functions
void Tile::print() {
	if (clicked) {
		std::cout << "|" << "?" << "|";
	}
	else if (flagged) {
		std::cout << "|F|";
	}
	else {
		std::cout << "|X|";
	}
}