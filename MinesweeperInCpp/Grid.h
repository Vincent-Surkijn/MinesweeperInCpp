#ifndef GRID_H
#define GRID_H


#define DEBUG

#include <iostream>
#include <vector>
#include "Random.h"
#include "Tile.h"


// Enum to define difficulty level
enum class Level{
	EASY,
	NORMAL,
	HARD,
	MAX
};



// Grid class definition
class Grid{
private:
	int flagsSet = 0;	// Amount of flags already set
	int clicks = 0;		// Amount of clicks done by user
	Level difficulty;	// Difficulty level of the game
	std::vector<coord> mineCoords;			// Vector with coordinates of the mines
	std::vector<std::vector<Tile*>>	field;	// Vector with all the tiles including mines

public:
	// Constructors
	Grid() {
		// Default level = easy
		difficulty = Level::EASY;
		// Generate mine coordinates
		generateMineCoords();
		// Populate field with tiles
		populateField();
	}

	Grid(Level difficulty) :difficulty{ difficulty } {
		// Set difficulty level
		this->difficulty = difficulty;
	#ifdef DEBUG
		std::cout << "Grid difficulty:" << static_cast<int>(this->difficulty) << "\n";
	#endif
		// Generate mine coordinates
		generateMineCoords();
		// Populate field with tiles
		populateField();
	}

	// Destructor
	~Grid() {
		int dims[2];
		// Store grid size in dims variable
		getGridSize(dims);
		// Clear all Tile ptrs
		for (int c = 0; c < dims[0]; ++c) {	// Loop through rows
			for (int r = 0; r < dims[1]; ++r) {
				delete(field[r][c]);
			}
			// Start a new line for the new row
			std::cout << "\n";
		}
		field.clear();
	}

	// Getters
	Level getDifficulty() {
		return difficulty;
	}

	std::vector<coord> getMineCoords() {
		return mineCoords;
	}

	int getNumberOfMines() {
		switch (difficulty)
		{
		case Level::EASY:
			return 10;
			break;
		case Level::NORMAL:
			return 40;
			break;
		case Level::HARD:
			return 99;
			break;
		default:
			throw "Invalid Level Enum state @Grid.h:getNumberOfMines()";
			break;
		}
	}

	// Return grid size as an array[rows,columns] in the passed parameter
	void getGridSize(int *result) {
		switch (difficulty)
		{
		case Level::EASY:
			// Rows
			result[0] = 8;
			// Columns
			result[1] = 8;
			break;
		case Level::NORMAL:
			// Rows
			result[0] = 16;
			// Columns
			result[1] = 16;
			break;
		case Level::HARD:
			// Rows
			result[0] = 30;
			// Columns
			result[1] = 16;
			break;
		default:
			throw "Invalid Level Enum state @Grid.h:getNumberOfMines()";
			break;
		}
	#ifdef DEBUG
		std::cout << "Returning size:" << result[0] << "," << result[1] << "\n";
	#endif
	}

	Tile* getTileAtCoord(coord c) {
		return field[c.row][c.col];
	}

	// Other functions
	void generateMineCoords();

	void populateField();

	void print();

	bool coordIsMine(coord c);

	int countNeighboringMines(coord c);

	/* Receives input from userand acts upon it
	 * Returns 0 if game continues
	 * Returns 1 if game is won
	 * Returns 2 if game is lost
	 */ 
	int receiveUserInput(UserInput input);
};

#endif // GRID_H