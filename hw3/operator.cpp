#include <iostream>
#include <string>

std::string operator*(std::string s, int n)
{
	std::string add = s;
	for (int i = 1; i < n; ++i)
	{
		s = s + add;
	}
	return s;
}

int main()
{
	std::string word;
	getline(std::cin, word);
	std::cout << word * 2 << std::endl;
}