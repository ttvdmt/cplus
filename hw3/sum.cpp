#include <iostream>
#include <string>

int sum(std::string& s)
{
	int sum = 0;
	size_t size = s.size();
	std::string number;
	int flag = 0;
	for(int i = 0; i < size; i++)
	{
		if(std::isdigit(s[i]))
		{
			number.push_back(s[i]);
			flag = 1;
		}
		else if(flag == 1){
			sum += std::stoi(number, nullptr, 10);
			number = "";
			flag = 0;
		}
	}
	return sum;
}

int main()
{
	std::string word;
	getline(std::cin, word);
	std::cout << sum(word) << std::endl;
}