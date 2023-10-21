#include <string>
#include <memory>
#include <vector>
#include <iostream>

class StringStack
{
private:

	std::unique_ptr<std::vector<std::string>> str = std::make_unique<std::vector<std::string>>();
	int mTop = -1;

public:

	void push(std::string& s)
	{
		(*str).push_back(s);
		mTop++;
	}

	void push(std::string&& s)
	{
		(*str).push_back(std::move(s));
		mTop++;
	}

	void print()
	{
		std::cout << '(';
		for (int i = 0; i < mTop; i++)
		{
			std::cout << (*str)[i] << ',';
		}
		std::cout << (*str)[mTop] << ')' << std::endl;
	}

	std::string pop()
	{
		mTop--;
		return std::move((*str)[mTop + 1]);
	}
};