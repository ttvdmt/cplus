#include <iostream>

namespace myspace
{
	void printNTimes(const char& str, int n = 10)
	{
		for(int i = 0; i < n; i++)
		{
			std::cout << str;
		}
	}
}

int main()
{
	myspace::printNTimes(1);
}