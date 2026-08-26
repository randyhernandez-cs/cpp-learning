#include <iostream>
#include <string>
#include <vector>

struct Player
{
	std::string name{ "Character" };
	int health{ 100 };
	int level{ 1 };
};
void displayPlayers(const std::vector<Player>& x)
{
	for (int y{}; y < x.size(); ++y)
	{
		std::cout << "This index number is: " << y << '\n';
		std::cout << "Their name is: " << x.at(y).name << '\n';
		std::cout << "Their health is: " << x.at(y).health << '\n';
		std::cout << "Their level is: " << x.at(y).level << '\n';
	}
}
void playerRoster()
{
	Player alice{ "Alice", 30, 6 };
	Player bob{ "Bob", 100, 56 };
	Player charlie{ "Charlie", 77, 100 };
	std::vector characters{ alice, bob, charlie };
	displayPlayers(characters);
}