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
void sensorEdit(std::array<Sensor, 4>& storage,const std::size_t& x)
{
	double tempChange{};
	std::cout << "You choose " << storage.at(x).name << '\n' << "which has a temperature of: " << storage.at(x).temperature << '\n';
	std::cout << "Enter how much the temperature either decreased or increased: ";
	std::cin >> tempChange;
	storage.at(x).temperature += tempChange;
}

int main()
{
	std::size_t x{};
	std::array <Sensor, 4> sensorStorage{
		Sensor{"Bedroom", 74},
		Sensor{"Garage", 83.3},
		Sensor{"Living Room", 78.2},
		Sensor{"Attic", 88 }
	};
	std::cout << "Which sensor do you want to change the temperature on?" << '\n';
	for (std::size_t i{ 0 }; i < sensorStorage.size();++i)
	{
		std::cout << i << '.' << sensorStorage.at(i).name << '\n';
	}
	std::cin >> x;
	sensorEdit(sensorStorage, x);
	std::cout << "Your updated temperature is: " << sensorStorage.at(x).temperature << '\n';
}