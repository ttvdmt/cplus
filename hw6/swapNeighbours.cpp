#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <utility>

void swapNeighbours(auto it1, auto it2)
{
	size_t size = 0;
	auto size_it = it1;

	for (; size_it != it2; size_it++)
	{
		size++;
	}

	auto it = it1;
	for (size_t n = 0; n != size/2; n+=1)
	{
		auto itnext = it;
		itnext++;
		auto itnext2 = itnext;
		itnext2++;

		std::swap(*it, *itnext);

		it = itnext2; 
	}
}

int main()
{
	std::vector<int> v = {10, 20, 30, 40, 50};
	swapNeighbours(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << ' ';
	}
}