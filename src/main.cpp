#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <iostream>
#include <memory>

#include "objects\wall.hpp"
#include "settings.hpp"
#include "maze.hpp"

int main()
{
	Settings settings;
	settings.resX = 800;
	settings.resY = 600;
	settings.row = 10;
	settings.col = 10;

	Maze maze(settings.row, settings.col);
	maze.generate();

	sf::RenderWindow window(sf::VideoMode(settings.resX, settings.resY), "Maze");

	std::vector<std::unique_ptr<Object>> objects;

	objects.emplace_back(std::make_unique<Wall>(400.0f, 300.0f, 200.0f, 50.0f, true));
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear(sf::Color::Black);

		for (auto& i : objects)
		{
			i->update();
		}

		for (auto& i : objects)
		{
			i->draw(window);
		}
		window.display();
	}
}