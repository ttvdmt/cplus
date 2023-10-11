#include <iostream>
#include <string>
#include <cctype>

void changereg(std::string& word)
{
	if (static_cast<int>(word[0]) != tolower(word[0]))
	{
		word[0] = static_cast<char>(tolower(word[0]));
	}
	else
	{
		word[0] = static_cast<char>(toupper(word[0]));
	}
}

int main()
{
	std::string word;
	getline(std::cin, word);
	
	changereg(word);

	std::cout << word <<std::endl;
}