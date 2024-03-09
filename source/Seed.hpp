#include <ctime>
#include <cmath>
#pragma once
class Seed {
public:
	static int generateRandomSeed(int x) {
		int min = std::pow(10, x - 1);
		int max = std::pow(10, x) - 1;

		return min + std::rand() % (max - min + 1);
	}
};
class Get {
public:
	static unsigned int Seed;
	Get() {
		Seed = Seed::generateRandomSeed(64);
	}
};