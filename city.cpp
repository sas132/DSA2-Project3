#include "city.hpp"
#include <iostream>
#include "tour.hpp"

City::City(int newCities)
{
	numCities = newCities;
	smallestCity = 1000; //ubsurdly large number for purposes of testing
	bestTour = nullptr;

	for(int i = 0; i < numCities; i++)
	{
		for(int j = 0; j < numCities; j++)
		{
			cityDistances[i][j] = -1;
		}
	}
}

City::City(int newCities, int cities[][20])
{
	numCities = newCities;
	smallestCity = 1000; //ubsurdly large number for purpose of testing	
	bestTour = nullptr;

	for(int i = 0; i < numCities; i++)
	{
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
}

void City::goOnTour(int citiesVisited, int visited[], int distance)
{
	if(citiesVisited == 0)
	{
		for(int i = 0; i < numCities; i++)
		{
			visited[0] = i;
			goOnTour(1, visited, 0);
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
				int newDistance = distance + cityDistances[visited[citiesVisited - 1]][m];
				goOnTour(citiesVisited + 1, visited, newDistance);
			}
		}
	}
	else
	{
		distance += cityDistances[visited[citiesVisited - 1]][visited[0]];
		if(distance < smallestCity)
		{
			smallestCity = distance;
			Tour* tempTour = new Tour(distance, visited, numCities);
			bestTour = tempTour;
		}
		print(visited, distance);
	}
}

void City::print(int visited[], int distance)
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
