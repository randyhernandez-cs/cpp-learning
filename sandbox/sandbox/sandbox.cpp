// Sandbox - for testing and experimenting with C++ concepts
#include <iostream>
#include <string>
#include <vector>
#include <array>

struct Sensor 
{
	std::string name{ "" };
	double temperature{};
};

int main()
{
	std::array <Sensor, 4> sensorStorage{
		Sensor{"Bedroom", 74},
		Sensor{"Garage", 83.3},
		Sensor{"Living Room", 78.2},
		Sensor{"Attic", 88 }
	};
	std::cout << sensorStorage.at(0).name;
}