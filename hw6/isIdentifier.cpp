#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

bool isIdentifier(std::string_view s)
{
	return std::all_of(s.begin(), s.end(), 
		[s](char c){return (std::isalpha(c) || c == '_' || std::isdigit(c)) && !std::isdigit(s[0]);});
}

int main()
{
	std::string s = "my-name";

	std::cout << std::boolalpha << isIdentifier(s) << std::endl;
}