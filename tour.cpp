#include "tour.hpp"

Tour::Tour()
{
	distance = -1;
	for(int i = 0; i < 20; i++)
	{
		path[i] = -1;
	}
}

Tour::Tour(int newDistance, int newPath[], int numCities)
{
	distance = newDistance;

	for(int i = 0; i < numCities; i++)
	{
		path[i] = newPath[i];
	}
}

void Tour::setDistance(int newDistance)
{
	distance = newDistance;
}

void Tour::setPath(int newPath[], int numCities)
{
	for(int i = 0; i < numCities; i++)
	{
		path[i] = newPath[i];
	}
}

int Tour::getDistance()
{
	return distance;
}

int Tour::getCity(int index)
{
	return path[index];
}
