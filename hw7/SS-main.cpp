#include <iostream>
#include <string>
#include "StringStack.hpp"

int main()
{
	StringStack ss;
	std::string a {"Cat"};

	ss.push(a);
	ss.push(std::string{"Mouse"});
	ss.print();
	std::cout << a << std::endl;

	ss.push(std::move(a));
	ss.print();
	std::cout << a << std::endl;

	std::cout << ss.pop() << std::endl;
	ss.print();
	std::cout << ss.pop() << std::endl;
	std::cout << ss.pop() << std::endl;
	ss.print();
}