// Sandbox - for testing and experimenting with C++ concepts
#include <iostream>
#include <string>

struct player
{
	std::string name{};
	int health{};
	int level{};
	bool alive{};
};

int health(int& health)
{
	int damage{};
	std::cout << "please enter how much damage you want to take" << '\n';
	std::cin >> damage;
	health = health - damage;
	return health;
}

int main()
{
	player Cin{ "Cin", 100, 10, true  };
	std::cout << "The name of this character is: " << Cin.name << '\n';
	std::cout << "The health of this character is: " << Cin.health << '\n';
	std::cout << "The level of this character is: " << Cin.level << '\n';
	std::cout << "Alive of this character is: " << Cin.alive << '\n';
	health(Cin.health);
	std::cout << "Cin has " << Cin.health << " health" << '\n';
}
