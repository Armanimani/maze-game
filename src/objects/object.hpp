#pragma once
#include <SFML\Graphics.hpp>

class Object
{
public:
	virtual void draw(sf::RenderWindow&) = 0;
	virtual void update() {};
};