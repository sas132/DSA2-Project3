#include "permutation.hpp"
#include "tour.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Permutation::Permutation(Tour* previous, int newCities)
{
	current = previous;
	numCities = newCities;

	for(int i = 0; i < numCities; i++)
	{
		visited[i] = current->getCity(i);
	}
}

void Permutation::swap(int first, int second)
{
	int tempA = visited[first];
	int tempB = visited[second];

	visited[first] = tempB;
	visited[second] = tempA;
}

Tour* Permutation::perm()
{
	for(int i = 0; i < numCities; i++)
	{
		int m = numCities - 2;
		while(visited[m] > visited[m + 1])
		{
			m = m - 1;
		}
		int k = numCities - 1;
		while(visited[m] > visited[k])
		{
			k = k - 1;
		}
		swap(m, k);
		
		int p = m + 1;
		int q = numCities - 1;

		while(p < q)
		{
			swap(p, q);
			p++;
			q--;
		}
		current->setPath(visited);
		current->updateDistance();
	}
	current->print();
	return current;
}

void Permutation::crossover()
{
	int cross[numCities / 2];
	srand(time(NULL));

	int counter = 0;
	for(int i = (numCities / 2) - 1; i < numCities; i++)
	{
		cross[counter] = visited[i];
		counter++;
	}
	counter = 0;
	for(int j = 1; j < (numCities / 2) + 1; j++)
	{
		int loc = rand() % j;
		int tempA = cross[counter];
		int tempB = cross[loc];
		
		cross[counter] = tempB;
		cross[loc] = tempA;
		counter++;
	}

	counter = 0;
	for(int k = (numCities / 2) - 1; k < numCities; k++)
	{
		visited[k] = cross[counter];
		counter++;
	}

	current->setPath(visited);
	current->updateDistance();
	current->print();
}
