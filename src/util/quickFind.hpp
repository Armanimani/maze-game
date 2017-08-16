#pragma once

#include <vector>
#include <algorithm>
#include <numeric>

class QuickFind
{
	using Size = std::size_t;

public:
	explicit QuickFind(Size n);

	bool isConnected(Size p, Size q);
	void connect(Size p, Size q);
	Size numberOfPartition();
	Size size();

protected:
	Size size_;
	std::vector<Size> v_;
};

inline
QuickFind::QuickFind(Size n) : size_(n)
{
	v_.resize(size_);
	std::iota(v_.begin(), v_.end(), 0);
}

inline
bool QuickFind::isConnected(Size p, Size q)
{
	return (v_[p] == v_[q]) ? true : false;
}

inline
void QuickFind::connect(Size p, Size q)
{
	auto id = std::minmax(v_[p], v_[q]);
	auto oldId = id.second;
	std::replace_if(v_.begin(), v_.end(), [oldId](Size v) { return (v == oldId) ? true : false; }, id.first);
}

inline
QuickFind::Size QuickFind::numberOfPartition()
{
	auto temp = v_;
	std::sort(temp.begin(), temp.end());
	return std::distance(temp.begin(), (std::unique(temp.begin(), temp.end())));
}

inline
QuickFind::Size QuickFind::size()
{
	return size_;
}