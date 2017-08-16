#pragma once

#include "object.hpp"


class Wall : public Object
{
public:
	Wall(float posX, float posY, float length, float thickness, bool vert = false, sf::Color color = sf::Color::White);

	void draw(sf::RenderWindow& window) { window.draw(shape_); }

protected:
	float posX_{};
	float posY_{};
	float length_{};
	float thickness_{};

	sf::Color color_;
	sf::RectangleShape shape_;
};