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
	int numTours;
	double smallestTour;
	Tour* bestTour; //elite 1

public:
	City(int newCities);
	City(int newCities, int newTours,  double cities[][20]);
	Tour* goOnTour(int citiesVisited, int visited[], double distance, Tour* currentBest);
	Tour* getBest();
};
#endif
