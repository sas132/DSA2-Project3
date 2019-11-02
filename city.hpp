#ifndef CITY
#define CITY

#include <time.h>
#include <iostream>
#include "tour.hpp"

class City
{
private:
	double cityDistances[20][20];
	int numCities;
	double smallestTour;
	Tour* bestTour; //elite 1
	Tour* permedTour; //elite 2

public:
	City(int newCities);
	City(int newCities, double cities[][20]);
	Tour* goOnTour(int citiesVisited, int visited[], double distance, Tour* currentBest);
	Tour* getBest();
	//Tour* getPermed();
	void print(int visited[], double distance);
	//void permutation();
};
#endif
