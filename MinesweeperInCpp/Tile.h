#ifndef TILE_H
#define TILE_H


#include <iostream>
#include "Structs.h"


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

	Tile(coord c, int neighboringMines) : c{ c }, neighboringMines{ neighboringMines } {
		flagged = false;
		clicked = false;
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

	void setNeighboringMines(int neighboringMines);

	// Other functions
	virtual void print();

	virtual bool isMine() {
		return false;
	}
};



// Mine class definition
class Mine: public Tile {

public:
	// Constructors
	Mine() = default;

	Mine(coord c) : Tile(c) {}

	// Other functions
	void print();

	bool isMine() {
		return true;
	}
};

#endif // TILE_H