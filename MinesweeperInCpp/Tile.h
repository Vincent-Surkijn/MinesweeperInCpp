#include <iostream>
#include "Coord.h"


// Tile class definition
class Tile {
private:
	bool flagged;
	bool clicked;
	int neighboringMines;
	coord c;

public:
	// Constructors
	Tile() {
		flagged = false;
		clicked = false;
		neighboringMines = 0;
		c = { 0,0 };
	}
	
	Tile(coord c) : c{ c } {
		flagged = false;
		clicked = false;
		neighboringMines = 0;
	}

	// Getters
	bool getClicked() {
		return clicked;
	}

	bool getFlagged() {
		return flagged;
	}

	int getNeighboringMines() {
		return neighboringMines;
	}

	coord getCoords() {
		return c;
	}

	// Setters
	void setClicked(bool clicked);

	void setFlagged(bool flagged);

	// Other functions
	virtual void print();

};



// Mine class definition
class Mine: public Tile {

public:
	// Constructors
	Mine() = default;

	Mine(coord c) : Tile(c) {}

	// Other functions
	void print();
};