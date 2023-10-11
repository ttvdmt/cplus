#include <iostream>
#include <string>

void truncateToDot(std::string& s)
{
	size_t id = s.find('.', 0);
	s = s.substr(0, id);
}

int main()
{
	std::string word;
	getline(std::cin, word);
	truncateToDot(word);
	std::cout << word << std::endl;
}