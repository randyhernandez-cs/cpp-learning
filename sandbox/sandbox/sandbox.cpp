// Sandbox - for testing and experimenting with C++ concepts
#include <iostream>
#include <string>
#include <vector>

struct Player
{
	std::string name{ "Character" };
	int health{ 100 };
	int level{ 1 };
};

void displayPlayers(const std::vector<Player>& character)
{
	for (const auto& player : character)
	{
		std::cout << "Name: " << player.name << '\n';
		std::cout << "Health: " << player.health << '\n';
		std::cout << "Level: " << player.level << '\n';
	}
}
void damagePlayers(std::vector<Player>& character)
{
	for (auto& player : character)
	{
		player.health -= 10;
		std::cout << player.health << '\n';
	}
}
void healthSelect(const std::vector<Player>& character)
{
	for (auto& player : character)
	{
		if (int health{ 50 }; player.health < health)
		{
			std::cout << "Danger!" << '\n';
			std::cout << player.name << " is under half health!" << '\n';
		}
	}
}

int main()
{
	Player alice{ "Alice", 30, 6 };
	Player bob{ "Bob", 100, 56 };
	Player charlie{ "Charlie", 77, 100 };
	std::vector characters{ alice, bob, charlie };
	displayPlayers(characters);
	damagePlayers(characters);
	healthSelect(characters);
}