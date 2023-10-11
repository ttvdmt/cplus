#include <map>
#include <iostream>
#include <utility>

std::map<int, int> add(int n)
{
	std::map<int, int> map;
	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;

		if (map.find(x) == map.end())
			map.insert(std::pair<int, int> (x, 1));
		else
			map[x] += 1;
	}
	return map;
}

int main()
{
	int n;
	std::cin >> n;

	std::map<int, int> map = add(n);
	std::map<int, int>::iterator it = map.begin();

	for(; it != map.end(); it++)
	{
		std::cout << it->first << ' ' << it->second << std::endl;
	}
}