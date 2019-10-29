#ifndef TOUR
#define TOUR

class Tour
{
private:
	double distance;
	int path[];

public:
	Tour();
	Tour(double newDistance, int newPath[], int numCities);
	~Tour();
	void setDistance(double newDistance);
	void setPath(int newPath[], int numCities);
	double getDistance();
	int getCity(int index);
};
#endif
