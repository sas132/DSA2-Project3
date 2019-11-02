CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = tour.o city.o permutation.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o *.gch core main
