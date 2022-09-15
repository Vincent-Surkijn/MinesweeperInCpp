#pragma once

#include <iostream>
#include <vector>
#include "Random.h"


enum class Level
{
	EASY,
	NORMAL,
	HARD
};

struct coord
{
	int x{0};
	int y{0};
};


class Grid{
private:
	Level difficulty = Level::EASY;
	std::vector<coord> mineCoords;

public:
	Grid() {
		for (int i = 0; i < 10; ++i) {
			coord c;
			do {
				c = coord{ randInt(0,9), randInt(0,9) };
				mineCoords[i] = c;
			} while (not std::count_if(mineCoords.begin(), mineCoords.end(), &c));
		}
	}

	Level getDifficulty() {
		return difficulty;
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

	void print();
};