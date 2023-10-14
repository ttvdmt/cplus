#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		std::cin >> num;
		v.push_back(num);
	}

	auto it_max = std::max_element(v.begin(), v.end());

	std::sort(v.begin(), it_max);
	std::sort(it_max, v.end(), [](int a, int b){return a > b;});

	for(int i = 0; i < n; i++)
	{
		std::cout << v[i] << ' ';
	}
}