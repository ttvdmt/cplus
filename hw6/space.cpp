#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

void spacetoend(std::string& s)
{
	std::stable_partition(s.begin(), s.end(), [](char c){return c != ' ';});
}


int main()
{
	std::string s = "cats and dogs";
	spacetoend(s);

	std::cout << s << std::endl;
}