#include "city.hpp"
#include <iostream>
#include "tour.hpp"

City::City(int newCities)
{
	numCities = newCities;
	smallestTour = 1000.0; //ubsurdly large number for purposes of testing
	bestTour = nullptr;

	for(int i = 0; i < numCities; i++)
	{
		for(int j = 0; j < numCities; j++)
		{
			cityDistances[i][j] = -1;
		}
	}
}

City::City(int newCities, double cities[][20])
{
	numCities = newCities;
	smallestTour = 1000.0; //ubsurdly large number for purpose of testing	
	bestTour = nullptr;
	int visited[newCities];

	for(int i = 0; i < numCities; i++)
	{
		visited[i] = -1;
		for(int j = 0; j < numCities; j++)
		{
			if(i == j)
			{
				cityDistances[i][j] = -1;
			}
			else
			{
				cityDistances[i][j] = cities[i][j];
			}
		}
	}
	bestTour = goOnTour(0, visited, 0.0, nullptr);
}

Tour* City::goOnTour(int citiesVisited, int visited[], double distance, Tour* currentBest)
{
	if(citiesVisited == 0)
	{
		for(int i = 0; i < numCities; i++)
		{
			visited[0] = i;
			currentBest =  goOnTour(1, visited, 0, currentBest);
		}
	}
	else if(citiesVisited > 0 && citiesVisited < numCities)
	{
		for(int m = 0; m < numCities; m++)
		{
			bool cityHappened = false;
			for(int n = 0; n < citiesVisited; n++)
			{
				if(visited[n] == m)
				{
					cityHappened = true;
				}
			}

			if(cityHappened == false)
			{
				visited[citiesVisited] = m;
				double newDistance = distance + cityDistances[visited[citiesVisited - 1]][m];
				currentBest = goOnTour(citiesVisited + 1, visited, newDistance, currentBest);
			}
		}
	}
	else
	{
		distance += cityDistances[visited[citiesVisited - 1]][visited[0]];
		if(distance < smallestTour)
		{
			if(smallestTour == 1000.0)
			{
				Tour tempTourA(distance, visited, numCities);
				currentBest = &tempTourA;
				smallestTour = distance;
			}
			else if(smallestTour > distance && smallestTour != 1000.0)
			{
				Tour tempTourB(distance, visited, numCities);
				currentBest = &tempTourB;
				smallestTour = distance;
			}
		}
		print(visited, distance);
	}
	return currentBest;
}

void City::print(int visited[], double distance)
{
	std::cout << "City order: ";
	for(int i = 0; i < numCities; i++)
	{
		std::cout << visited[i] << " ";
	}
	std::cout << visited[0];

	std::cout << "\nDistance: " << distance << std::endl << std:: endl;
}

Tour* City::getBest()
{
	return bestTour;
}
