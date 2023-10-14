#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <utility>

auto bestNeighbours(auto it1, auto it2, auto arg)
{	
	size_t size = 0;
	auto size_it = it1;

	for (; size_it != it2; size_it++)
	{
		size++;
	}

	int max = 0;
	auto max_it = it1;
	auto it = it1;
	for (int n = 0; n != size - 1; n++)
	{
		auto itnext = it;
		itnext++;

		if (arg(*it, *itnext) > max)
		{
			max = arg(*it, *itnext);
			max_it = it;
		}
		it = itnext;
	}
	return max_it;
}

int main()
{
	std::vector<int> v = {50, 10, 10, 20, 90, 30, 40, 60, 80, 20};

	std::cout << *bestNeighbours(v.begin(), v.end(), [](int a, int b){return a + b;}) << std::endl;
}