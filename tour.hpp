#ifndef TOUR
#define TOUR

class Tour
{
private:
	int distance;
	int path[];

public:
	Tour();
	Tour(int newDistance, int newPath[], int numCities);
	~Tour();
	void setDistance(int newDistance);
	void setPath(int newPath[], int numCities);
	int getDistance();
	int getCity(int index);
};
#endif
