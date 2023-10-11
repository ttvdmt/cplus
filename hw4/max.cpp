#include <vector>
#include <iostream>
#include <string>

template <typename T>
auto max(const T& v)
{
	auto M = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] > M)
		{
			M = v[i];
		}
	}
	return M;
}

int main()
{
	std::vector<int> v = {10, 20, 30, 40, 50};
	auto M = max(v);
	std::cout << M << std::endl;
}