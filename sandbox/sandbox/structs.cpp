#include <iostream>
#include <string>

struct player
{
	std::string name{};
	int totalHealth{};
	int level{};
	bool alive{};
};

void health(player& Character)
{
	int damage{};
	std::cout << "please enter how much damage you want to take" << '\n';
	std::cin >> damage;
	Character.totalHealth = Character.totalHealth - damage;
}

void fatality(player& Character)
{
	if (Character.totalHealth <= 0)
	{
		Character.totalHealth = 0;
		std::cout << "Your character is dead!" << '\n';
		Character.alive = false;
	}
	else
	{
		std::cout << "Your character is alive!" << '\n';
		Character.alive = true;
	}
}
void displayCharacter(const player& Character)
{
	std::cout << "The address of the character struct is: " << &Character << '\n';
	std::cout << "The name of this character is: " << Character.name << '\n';
	std::cout << "The health of this character is: " << Character.totalHealth << '\n';
	std::cout << "The level of this character is: " << Character.level << '\n';
}

void pointCharacter(player* x)
{
	std::cout << x << '\n';
	std::cout << x->alive << '\n';
	std::cout << x->name << '\n';
	std::cout << x->totalHealth << '\n';
	x->level = 2;
}


void Char()
{
	player* x{ nullptr };
	player Character{ "", 100, 1, true };
	std::cout << "Create the name for this character: ";
	std::cin >> Character.name;
	displayCharacter(Character);
	health(Character);
	fatality(Character);
	std::cout << Character.name << " has " << Character.totalHealth << " health" << '\n';
	x = { &Character };
	pointCharacter(x);
	displayCharacter(Character);
	fatality(Character);
}