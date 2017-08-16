#include "wall.hpp"

Wall::Wall(float posX, float posY, float length, float thickness, bool vert, sf::Color color) : posX_(posX), posY_(posY), length_(length), thickness_(thickness), color_(color)
{
	shape_.setSize({ length_, thickness_ });
	shape_.setFillColor(color_);

	float offsetX{};
	float offsetY{};
	if (vert == true)
	{
		shape_.setRotation(90);
		offsetX = thickness_ * -0.5f;
		offsetY = length_ * 0.5f;
	}
	else
	{
		offsetX = length_ * 0.5f;
		offsetY = thickness_ * 0.5f;
	}

	shape_.setPosition({ posX_ - offsetX, posY_ - offsetY });
}
