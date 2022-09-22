#include "Tile.h"

void Mine::print(bool clicked) {
	if (getClicked() || clicked) {
		std::cout << "|" << "O" << "|";
	}
	else if (getFlagged()) {
		std::cout << "|F|";
	}
	else {
		std::cout << "|X|";
	}
}