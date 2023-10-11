#include <vector>
#include <iostream>
#include<span>

std::vector<int> lastDigits1(const std::vector<int>& num)
{
	std::vector<int> v;
	for (int i = 0; i < num.size(); i++)
	{
		v.push_back(num[i] % 10);
	}
	return v;
}

void lastDigits2(std::vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] % 10;
	}
}

void lastDigits3(std::vector<int>* pv)
{
	for (int i = 0; i < pv->size(); i++)
	{
		(*pv)[i] = (*pv)[i] % 10;
	}
}

void lastDigits4(std::span<int> sp)
{
	for (int i = 0; i < sp.size(); i++)
	{
		sp[i] = sp[i] % 10;
	}
}

int main()
{
	std::vector<int> num = {11, 22, 33};
}