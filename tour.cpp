#include "tour.hpp"
#include <string>
#include <iostream>

Tour::Tour()
{
	for(int i = 0; i < 20; i++)
	{
		path[i] = -1;
	}
}

Tour::Tour(double newDistance, int newPath[], int newCities, double city[][20])
{
	for(int i = 0; i < 20; i++)
	{
		path[i] = -1;
		for(int j = 0; j < 20; j++)
		{
			distances[i][j] = city[i][j];
		}
	}

	numCities = newCities;
	distance = newDistance;
	setPath(newPath);
}

Tour::~Tour()
{

}

void Tour::setDistance(double newDistance)
{
	distance = newDistance;
}

void Tour::setPath(int newPath[])
{
	int location = -1;
	for(int i = 0; i < numCities; i++)
	{
		if(newPath[i] == numCities)
		{
			path[i] = fixPath(newPath);
		}
		else
		{
			int num = newPath[i];
			path[i] = num;
		}
	}
}

double Tour::getDistance()
{
	return distance;
}

int Tour::getCity(int index)
{
	return path[index];
}

int Tour::fixPath(int newPath[])
{
	bool happenedArray[numCities];
	for(int k = 0; k < numCities; k++)
	{
		happenedArray[k] = false;
	}

	for(int i = 0; i < numCities; i++)
	{
		for(int j = 0; j < numCities; j++)
		{
			if(newPath[i] == j)
			{
				happenedArray[j] = true;
			}
		}
	}
	
	for(int m = 0; m < numCities; m++)
	{
		if(happenedArray[m] == false)
		{
			return m;
		}
	}
}

void Tour::print()
{
	std::cout << "City order: ";
	for(int i = 0; i < numCities; i++)
	{
		std::cout << path[i] << " ";
	}
	std::cout << path[0];
	std::cout << "\nDistance: " << distance << std::endl;
}

void Tour::updateDistance()
{
	distance = 0;

	for(int i = 1; i < numCities; i++)
	{
		distance += distances[path[i - 1]][path[i]];
	}

	distance += distances[0][numCities - 1];
}
