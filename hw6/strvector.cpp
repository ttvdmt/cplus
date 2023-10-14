#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>

void str_reverse(std::vector<std::string>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::reverse(v[i].begin(), v[i].end());
	}
	std::reverse(v.begin(), v.end());
}

int main()
{
	std::vector<std::string> v = {"cat", "dog", "mouse", "elephant"};
	str_reverse(v);
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << ' ';
	}
}