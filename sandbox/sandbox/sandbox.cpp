// Sandbox - for testing and experimenting with C++ concepts
#include <iostream>
#include <string>
#include <vector>
struct player
{
	std::string name{ "Character" };
	int health{100};
	int level{1};
};
void displayPlayers(const std::vector<player>& x)
{
	for (int y{}; y < x.size(); ++y)
	{
		std::cout << x.at(y).name << '\n';
		std::cout << x.at(y).health << '\n';
		std::cout << x.at(y).level << '\n';
	}
}
int main()
{
	player A;
	player B;
	player C;
	std::vector characters{A, B, C};
	displayPlayers(characters);
}