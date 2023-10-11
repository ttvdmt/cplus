#include <vector>
#include <iostream>
#include <math.h>

std::vector<std::pair<int, int>> factorization(int n)
{	
	std::vector<std::pair<int, int>> dels;
	int del = 0;
	int count = 0;
	for (int i = 2; i < sqrt(n) + 1;)
	{
		if (n % i == 0)
		{
			del = i;
			count++;
			n /= i;
		}
		else 
		{
			i++;
			if (count != 0)
			{
				dels.push_back({del, count});
			}
			count = 0;
		}
	}
	if (n > 1)
	{
		dels.push_back({n, 1});
	}
	return dels;
}

int main()
{
	int n = 626215995;
	std::vector<std::pair<int, int>> v = factorization(n);
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i].first << ' ' << v[i].second << std::endl;
	}
}