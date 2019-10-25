#include <iostream>
#include "tour.hpp"
#include "city.hpp"

//int NUM_CITIES;
//int CITY_DISTANCES[20][20];

int main(int argc, char **argv)
{
	std::cout << "Hello World\n";
	
	int distances[5][20] = {{-1, 1, 2, 3, 4},
			 	{1, -1, 2, 3, 4},
				{1, 2, -1, 3, 4},
				{1, 2, 3, -1, 4},
				{1, 2, 3, 4, -1}};

	int visited[5] = {-1, -1, -1, -1, -1};
	City tempCity(5, distances);
	tempCity.goOnTour(0, visited, 0);
	
	return 0;
}
