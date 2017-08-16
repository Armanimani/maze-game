#pragma once

#include "util/grid.hpp"
#include "util/quickFind.hpp"

class Object;
class Settings;

class Maze
{
	using Size = std::size_t;
	using Union = QuickFind;

	struct Direction
	{
		static constexpr short up{ 1 };
		static constexpr short left{ 2 };
		static constexpr short down{ 3 };
		static constexpr short right{ 4 };
	};

public:
	Maze(const Size row, const Size col) : grid_(row, col), uf_(grid_.getSize()) {}

	void generate();
	void generateObjects(const Settings& settings, std::vector<Object>& obj);

	const Grid& getGrid() const { return grid_; }
	const Union& getUF() const { return uf_; }

protected:
	Grid grid_;
	Union uf_;

	Size start{};
	Size finish{};
};
