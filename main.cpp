#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "tour.hpp"
#include "city.hpp"
#include "permutation.hpp"

double CITY_DISTANCES[20][20];

void fileReader()
{
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
				CITY_DISTANCES[i][j] = current;
			}
		}
	}
}

int main(int argc, char **argv)
{
	fileReader();
	if(argc == 5)
	{
		int cities = std::stoi(argv[1]);
		int tours = std::stoi(argv[2]);
		double numPerm = std::stod(argv[4]);
		int numGen = std::stoi(argv[3]);
		int permCount = 0;

		City* tempCity = new City(cities, tours, CITY_DISTANCES);
		Tour* best = tempCity->getBest();
		Tour* second = best;

		Permutation* perm = new Permutation(second, cities);

		for(int i = 0; i < numGen; i++)
		{
			std::cout << "\n\nGeneration " << i + 1 << ":\n";
			perm->crossover();
			
			if(permCount < numPerm * numGen)
			{
				i++;
				std::cout << "\nGeneration " << i + 1 << ":\n";
				std::cout << "Permuatation " << permCount + 1 << ":\n";
				second = perm->perm();
				permCount++;
			}
		}
	}
	else
	{
		std::cout << "Error.\n";
	}
	return 0;
}
