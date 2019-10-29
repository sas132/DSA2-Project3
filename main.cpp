#include <iostream>
#include "tour.hpp"
#include "city.hpp"

//int NUM_CITIES;
//int CITY_DISTANCES[20][20];

int main(int argc, char **argv)
{
	std::cout << "Hello World\n";
	
	double distances[5][20] = {{-.1, .1, .2, .3, .4},
			 	{.1, -.1, .2, .3, .4},
				{.1, .2, -.1, .3, .4},
				{.1, .2, .3, -.1, .4},
				{.1, .2, .3, .4, -.1}};

	std::cout << "test1\n";
	City* tempCity = new City(5, distances);
	Tour* tempTour = tempCity->getBest();

	std::cout << tempTour->getDistance() << std::endl;
	
	return 0;
}
