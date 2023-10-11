#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <array>
#include <span>

template <typename T>
auto value_initialization(const T& a)
{
	return T(); 
}

template <typename U>
auto pairs(const U& v)
{
	using pairtype = std::pair<typename U::value_type, typename U::value_type>;
	using rtype = std::vector<pairtype>;
	pairtype p;
	rtype r;

	U vchanged = v;

	auto elem = v[0];
	auto zero = value_initialization(elem);
	if (v.size() % 2 != 0)
	{
		vchanged.push_back(zero);
	}

	for (int i = 0; i < vchanged.size() - 1; i += 2)
	{
		p = std::make_pair(vchanged[i], vchanged[i+1]);
		r.push_back(p);
	}
	return r;
}

int main()
{
	std::vector<int> v = {10, 20, 30, 40, 50};
	auto p = pairs(v);
	for (int i = 0; i < p.size(); i++)
	{
		std::cout << p[i].first << ' ' << p[i].second << std::endl;
	}
}