#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

int main()
{
	std::string s = "DOG AND!";
	auto result = std::all_of(s.begin(), s.end(), [](char c) {return !std::isalpha(c) || std::isupper(c);});
	std::cout << std::boolalpha << result << std::endl;
}