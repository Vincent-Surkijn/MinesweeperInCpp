#pragma once

// Struct for coordinates
struct coord {
	int x{ 0 };
	int y{ 0 };
};

// Overload to compare coordinates
bool operator==(coord& c1, coord& c2);