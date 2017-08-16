#include "maze.hpp"

#include "objects\wall.hpp"
#include "settings.hpp"

#include <memory>
#include <random>

void Maze::generate()
{
	start = 0;
	finish = grid_.getID(grid_.getNumberRow(), grid_.getNumberColumn());

	std::random_device generator;
	std::uniform_int_distribution<short> direction(Direction::up, Direction::right);
	std::uniform_int_distribution<Size> distribution(1, grid_.getSize());

	while (!uf_.isConnected(start, finish))
	{
		auto id = distribution(generator) - 1;
		auto dir = direction(generator);

		auto row = grid_.getRow(id);
		auto col = grid_.getColumn(id);
		switch (dir)
		{
		case Direction::up:
		{
			if (row != grid_.getNumberRow())
			{
				uf_.connect(id, grid_.getID(row + 1, col));
			}
			break;
		}
		case Direction::left:
		{
			if (col != 1)
			{
				uf_.connect(id, grid_.getID(row, col - 1));
			}
			break;
		}
		case Direction::down:
		{
			if (row != 1)
			{
				uf_.connect(id, grid_.getID(row - 1, col));
			}
			break;
		}
		case Direction::right:
		{
			if (col != grid_.getNumberColumn())
			{
				uf_.connect(id, grid_.getID(row, col + 1));
			}
			break;
		}
		}
	}
}

void Maze::generateObjects(const Settings& settings, std::vector<Object>& obj)
{
	auto numberCol = grid_.getNumberColumn();
	auto numberRow = grid_.getNumberRow();
	auto dx = std::min(settings.resY * 0.9f / numberCol, settings.resX * 0.9f / numberRow);
	auto thickness = 0.1 * dx;

	auto startX{ 0.05 * dx };
	auto startY{ 0.05 * dx };
	for (decltype(numberRow) i = 1; i != numberRow + 1; ++i)
	{
		for (decltype(numberCol) j = 1; j != numberCol + 1; ++j)
		{
			if (i != numberRow)
			{
				if (uf_.isConnected(grid_.getID(i, j), grid_.getID(i + 1, j)))
				{
					addWall(grid_.getID(i, j), grid_.getID(i + 1, j), false);
				}
			}
			if (j != numberCol)
			{
				if (uf_.isConnected(grid_.getID(i, j), grid_.getID(i, j + 1)))
				{
					addWall(grid_.getID(i, j), grid_.getID(i, j + 1), true);
				}
			}
		}
	}
}

void Maze::addWall(std::vector<Object>& objects, const std::size_t id1, const std::size_t id2, bool horizontal, const float length, const float thickness)
{
	const auto row1 = grid_.getRow(id1) - 1;
	const auto col1 = grid_.getColumn(id1) - 1;
	const auto row2 = grid_.getRow(id2) - 1;
	const auto col2 = grid_.getColumn(id2) - 1;
	if (horizontal)
	{
		objects.emplace_back(std::make_unique<Wall>(startX + 0.5 * (col1 + col2) * dx, startY + 0.5 * (row1 + row2) * dx));
	}
	else
	{
		walls_.push_back(wallGen_.getVertical(startX + 0.5 * (col1 + col2) * dx, startY + 0.5 * (row1 + row2) * dx));
	}
}