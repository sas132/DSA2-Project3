#ifndef PERM
#define PERM

#include "tour.hpp"

class Permutation
{
private:
	Tour* current;
	int numCities;
	int visited[];

public:
	Permutation(Tour* previous, int newCities);
	void swap(int first, int second);
	Tour* perm();
	void crossover();
};
#endif
