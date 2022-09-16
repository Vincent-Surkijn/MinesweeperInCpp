#include "Tile.h"

void Mine::print() {
	if (getClicked()) {
		std::cout << "|" << "O" << "|";
	}
	else if (getFlagged()) {
		std::cout << "|F|";
	}
	else {
		std::cout << "|X|";
	}
}