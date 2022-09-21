#include "Structs.h"

bool operator==(coord& c1, coord& c2) {
	return c1.row == c2.row && c1.col == c2.col;
}

std::ostream& operator <<(std::ostream& out, coord& c) {
	out << "Coord(row:" << c.row << ", column:" << c.col << ")";
	return out;
}

std::ostream& operator<<(std::ostream& out, UserInput& input) {
	out << "UserInput(act:" << input.act << ", coord:" << input.c << ")";
	return out;
}