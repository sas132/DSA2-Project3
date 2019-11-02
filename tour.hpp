#ifndef TOUR
#define TOUR

#include <string>

class Tour
{
private:
	double distance;
	int path[20];
	int numCities;
	double distances[20][20];

public:
	Tour();
	Tour(double newDistance, int newPath[], int newCities, double distances[][20]);
	~Tour();
	void setDistance(double newDistance);
	void setPath(int newPath[]);
	double getDistance();
	int getCity(int index);
	int fixPath(int newPath[]);
	void print();
	void updateDistance();
};
#endif
