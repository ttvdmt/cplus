#include <vector>
#include <iostream>

int sumEven(const std::vector<int>& v)
{
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	return sum;
}

int main()
{
	std::vector<int> nums {10, 20, 30, 40, 50};
	int sum = sumEven(nums);

	std::cout << sum <<std::endl;
}