#include "Random.h"

int randInt(int min, int max)
{
	// Seed our Mersenne Twister using the
	std::mt19937 mt{ static_cast<unsigned int>(
		std::chrono::steady_clock::now().time_since_epoch().count()
		) };

	// Create a reusable random number generator that generates uniform numbers between min and max
	std::uniform_int_distribution<> rand{ min, max };

	return rand(mt);
}
