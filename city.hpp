#ifndef CITY
#define CITY

#include <iostream>
#include "tour.hpp"

class City
{
private:
	int cityDistances[20][20];
	int numCities;
	int smallestCity;
	Tour* bestTour; //elite 1
	Tour* permedTour; //elite 2

public:
	City(int newCities);
	City(int newCities, int cities[][20]);
	void goOnTour(int citiesVisited, int visited[], int distance);
	Tour* getBest();
	//Tour* getPermed();
	void print(int visited[], int distance);
};
#endif
