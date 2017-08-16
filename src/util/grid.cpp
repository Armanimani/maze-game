#include "grid.hpp"

std::vector<Grid::Size> Grid::getBoundaries()
{
	std::vector<Size> ret(2 * (nRow_ + nCol_ - 2));

	Size cnt{};
	for (Size i = 1; i != nCol_; ++i, ++cnt)
	{
		ret[cnt] = getID(1, i);
	}

	for (Size i = 1; i != nRow_; ++i, ++cnt)
	{
		ret[cnt] = getID(i, nCol_);
	}

	for (Size i = nRow_; i != 1; --i, ++cnt)
	{
		ret[cnt] = getID(nCol_, i);
	}

	for (Size i = nRow_; i != 1; --i, ++cnt)
	{
		ret[cnt] = getID(i, 1);
	}

	return ret;
}