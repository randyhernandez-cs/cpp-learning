// Sandbox - for testing and experimenting with C++ concepts
#include <iostream>
#include <string>

struct player
{
	std::string name{};
	int totalHealth{};
	int level{};
	bool alive{};
};

void health(player& Cin)
{
	int damage{};
	std::cout << "please enter how much damage you want to take" << '\n';
	std::cin >> damage;
	Cin.totalHealth = Cin.totalHealth - damage;
}

void fatality(player& Cin)
{
	if (Cin.totalHealth <= 0)
	{
		Cin.totalHealth = 0;
		std::cout << "Your character is dead!" << '\n';
		Cin.alive = false;
	}
	else 
	{
		std::cout << "Your character is alive!" << '\n';
		Cin.alive = true;
	}
}

int main()
{
	player Cin{ "Cin", 100, 10, true  };
	std::cout << "The name of this character is: " << Cin.name << '\n';
	std::cout << "The health of this character is: " << Cin.totalHealth << '\n';
	std::cout << "The level of this character is: " << Cin.level << '\n';
	health(Cin);
	fatality(Cin);
	std::cout << "Cin has " << Cin.totalHealth << " health" << '\n';
}
