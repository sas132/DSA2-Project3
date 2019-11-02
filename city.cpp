#include "city.hpp"
#include <iostream>
#include <time.h>
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

City::City(int newCities, int newTours, double cities[][20])
{
	numCities = newCities;
	numTours = newTours;
	smallestTour = 1000.0; //ubsurdly large number for purpose of testing	
	int visited[numTours];

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

	for(int j = 0; j < numTours; j++)
	{
		visited[j] = -1;
	}

	struct timespec beforeBrute, afterBrute;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &beforeBrute);
	Tour* current = goOnTour(0, visited, 0.0, nullptr);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &afterBrute);
	int totalBruteTimeN = afterBrute.tv_nsec - beforeBrute.tv_nsec;
	int totalBruteTimeS = afterBrute.tv_sec - beforeBrute.tv_sec;

	int best[numCities];
	for(int j = 0; j < numCities; j++)
	{
		best[j] = current->getCity(j);
	}
	
	bestTour = new Tour(current->getDistance(), best, numTours, cityDistances);
	bestTour->print();
	std::cout << "brute time: " << totalBruteTimeS << "s " << totalBruteTimeN << "ns\n";
}

Tour* City::goOnTour(int citiesVisited, int visited[], double distance, Tour* current)
{
	int tempNum = numCities; //testing if just randomly using it works??
	if(citiesVisited == 0)
	{
		for(int i = 0; i < numCities; i++)
		{
			std::cout << "Loading city " << i << "/" << numCities << std::endl;
			visited[0] = i;
			current =  goOnTour(1, visited, 0, current);
		}
	}
	else if(citiesVisited > 0 && citiesVisited < numTours)
	{
		for(int m = 0; m < numCities; m++)
		{
			bool cityHappened = false;
			for(int n = 0; n < numTours; n++)
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
				current = goOnTour(citiesVisited + 1, visited, newDistance, current);
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
				Tour tempTourA(distance, visited, numTours, cityDistances);
				current = &tempTourA;
				smallestTour = distance;
			}
			else if(smallestTour > distance && smallestTour != 1000.0)
			{
				Tour tempTourB(distance, visited, numTours, cityDistances);
				current = &tempTourB;
				smallestTour = distance;
			}
		}
	}
	return current;
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
