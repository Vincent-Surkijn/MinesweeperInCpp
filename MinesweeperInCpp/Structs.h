#include <ostream>
#ifndef STRUCTS_H
#define STRUCTS_H


// Struct for coordinates
struct coord {
	int row{ 0 };
	int col{ 0 };
};

// Overload to compare coordinates
bool operator==(coord& c1, coord& c2);


// Overload to facilitate printing
std::ostream& operator<<(std::ostream& out, coord& c);


// Struct to pass input of user
struct UserInput {
	char act{ 'c' };
	coord c{ 0, 0 };
};


// Overload to facilitate printing
std::ostream& operator<<(std::ostream& out, UserInput& input);

#endif // STRUCTS_H