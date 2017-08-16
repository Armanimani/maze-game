#pragma once

#include <cstdlib>
#include <vector>

class Grid
{
	using Size = std::size_t;
public:
	Grid(const Size row, const Size col) : nRow_(row), nCol_(col) {}

	Size getID(const Size row, const Size col) const { return (row - 1) * nCol_ + (col - 1); }
	Size getRow(const Size id) const { return static_cast<Size>(id / nCol_) + 1; }
	Size getColumn(const Size id) const{ return (id % nRow_) + 1; }

	Size getSize() const { return nRow_ * nCol_; }
	Size getNumberRow() const { return nRow_; }
	Size getNumberColumn() const{ return nCol_; }

	Size getRight(const Size id) const
	{
		auto row = getRow(id);
		auto col = getColumn(id);
		return getID(row, col + 1);
	}

	Size getLeft(const Size id) const
	{
		auto row = getRow(id);
		auto col = getColumn(id);
		return getID(row, col - 1);
	}

	Size getUp(const Size id) const
	{
		auto row = getRow(id);
		auto col = getColumn(id);
		return getID(row + 1, col);
	}

	Size getDown(const Size id) const
	{
		auto row = getRow(id);
		auto col = getColumn(id);
		return getID(row - 1, col);
	}

	std::vector<Size> getBoundaries();

protected:
	Size nRow_{};
	Size nCol_{};
};