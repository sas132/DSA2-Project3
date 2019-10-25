#include "city.hpp"
#include <iostream>
#include "tour.hpp"

City::City(int newCities)
{
	numCities = newCities;
	//int blankVisited[numCities];

	for(int i = 0; i < numCities; i++)
	{
		for(int j = 0; j < numCities; j++)
		{
			cityDistances[i][j] = -1;
		}
		//blankVisited[1] = -1;
	}

	//get distances from .txt file
}

City::City(int newCities, int cities[][20])
{
	numCities = newCities;
	
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

/*void City::goOnTour(int citiesVisited, int visited[], int distance)
{
	if(citiesVisited > 0 && citiesVisited < numCities)
	{
		int previous = visited[citiesVisited - 1];
		for(int i = 0; i < numCities; i++)
		{
			std::cout << previous << " " << i << std::endl;
			bool currentVisited = false;
			if(visited[i] == i)
			{
				currentVisited = true;
			}
			if(currentVisited == false)
			{
				int newDistance = distance + cityDistances[previous][i];
				int newCitiesVisited = citiesVisited + 1;
				visited[citiesVisited] = i;

				goOnTour(newCitiesVisited, visited, newDistance);
			}
		}
	}
	else if(citiesVisited <= 0)
	{
		for(int j = 0; j < numCities; j++)
		{
			std::cout << j << std::endl;
			visited[0] = j;
			citiesVisited++;
		
			goOnTour(citiesVisited, visited, 0);
		}
	}
	else
	{
		print(visited, distance);
	}
}*/

void City::goOnTour(int citiesVisited, int visited[], int distance)
{
	if(citiesVisited == 0)
	{
		for(int i = 0; i < numCities; i++)
		{
			//std::cout << i << std::endl;
			visited[0] = i;
			goOnTour(1, visited, 0);
		}
	}
	else if(citiesVisited == 1)
	{
		for(int j = 0; j < numCities; j++)
		{
			if(visited[0] != j)
			{
				//std::cout << "    " <<  j << " ";
				visited[1] = j;
				distance = cityDistances[visited[0]][j];
				//std::cout << distance << std::endl;
				goOnTour(2, visited, distance);
			}
		}
	}
	else if(citiesVisited == 2)
	{
		for(int k = 0; k < numCities; k++)
		{
			if(visited[0] != k && visited[1] != k)
			{
				//std::cout << "        " << k << " ";
				visited[2] = k;
				int newDistance = distance + cityDistances[visited[1]][k];
				//std::cout << newDistance << std::endl;
				goOnTour(3, visited, newDistance);
			}
		}
	}
	else if(citiesVisited > 2 && citiesVisited < 5)
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
	/*else if(citiesVisited < numCities)
	{
		//std::cout << "test A\n";
		for(int j = 0; j < numCities; j++)
		{
			//std::cout << "test B\n";
			bool cityHappened = false;
			for(int k = 0; k < numCities; k++)
			{
				//std::cout << "test C\n";
				if(visited[j] == k)
				{
					//std::cout << "test D\n";
					cityHappened = true;
				}
			}

			if(cityHappened == false)
			{
				//std::cout << "test E\n";
				visited[citiesVisited - 1] = j;
				//std::cout << "test F\n";
				int newDistance = distance + cityDistances[visited[citiesVisited - 1]][j];
				//std::cout << "test G\n";
				goOnTour(citiesVisited + 1, visited, newDistance);
				//std::cout << "test H\n";
			}
		}
	}*/
	else
	{
		distance += cityDistances[visited[citiesVisited - 1]][visited[0]];
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

	std::cout << "\nDistance: " << distance << std::endl << std::endl;
}
