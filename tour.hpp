#ifndef TOUR
#define TOUR

#include <string>

class Tour
{
private:
	double distance;
	int path[20];
	int numCities;

public:
	Tour();
	Tour(double newDistance, int newPath[], int newCities);
	~Tour();
	void setDistance(double newDistance);
	void setPath(int newPath[]);
	double getDistance();
	int getCity(int index);
	int fixPath(int newPath[]);
	void print();
};
#endif
