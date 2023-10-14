#include <iostream>
#include <string>
#include <iterator>
#include<vector>

auto max_element(auto it1, auto it2)
{
	if (it1 == it2)
		return it1;

	auto max = it1;
	it1++;

	for (; it1 != it2; it1++)
	{
		if (*max < *it1)
			max = it1;
	}
	return max;
}

int main()
{
	std::vector<int> v = {1, 6, 3};

	std::cout << *max_element(v.begin(), v.end()) << std::endl; 
}