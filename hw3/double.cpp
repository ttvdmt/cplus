#include <iostream>
#include <string>
#include <string_view>

std::string repeat1(std::string_view s)
{
	std::string str = s.data();
	return str + str;
}

void repeat2(std::string& s)
{
	s = s + s;
}

void repeat3(std::string* s)
{
	size_t size = s->size();
	for (int i = 0; i < size; ++i)
	{
		s->push_back((*s)[i]);
	}
}

std::string* repeat4(std::string_view s)
{
	std::string* str = new std::string;
	std::string r = s.data();
	*str = r + r;
	return str;
}

int main()
{
	std::string word;
	getline(std::cin, word);
}