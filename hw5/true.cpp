#include <iostream>
#include <stack>
#include <string>
#include <string_view>

bool check(std::string_view s)
{
	std::stack<char> stack;

	for (int i = 0; i < s.size(); i++)
	{
		if (stack.empty())
			stack.push(s[i]);
		
		else
		{
			int c1 = s[i];
			int c2 = stack.top();


			if (c1 - c2 < 3 && c1 - c2 > 0)
			{
				stack.pop();
			}
			else
				stack.push(s[i]);

		}
	}
	return stack.empty();
}

int main()
{
	std::string str;
	getline(std::cin, str);

	std::cout << check(str) << std::endl;
}