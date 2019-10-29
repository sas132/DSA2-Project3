#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
//#include "file_reader.hpp"
#include "tour.hpp"
#include "city.hpp"

//int NUM_CITIES;
double CITY_DISTANCES[20][20];

void fileReader()
{
	//char* line;
	double current;

	std::ifstream cityText;
	cityText.open("distances.txt");

	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(i == j)
			{
				CITY_DISTANCES[i][j] = -1;
			}
			else
			{
				cityText >> current;
				//std::cout << current << std::endl;
				CITY_DISTANCES[i][j] = current;
			}
		}
	}
}

int main(int argc, char **argv)
{
	std::cout << "Hello World\n";
	fileReader();	
	/*double distances[5][20] = {{-.1, .1, .2, .3, .4},
			 	{.1, -.1, .2, .3, .4},
				{.1, .2, -.1, .3, .4},
				{.1, .2, .3, -.1, .4},
				{.1, .2, .3, .4, -.1}};*/
	std::cout << "Bonjour\n";
	City* tempCity = new City(10, CITY_DISTANCES);
	//std::cout << "any key to enter: ";
	//std::cin >> continueGoing;

	//fileReader();	

	return 0;
}
