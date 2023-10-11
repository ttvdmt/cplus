#include <iostream>
#include <string>
#include <string_view>

int main()
{
	int* num = new int{123};
	std::string* str = new std::string{"Cats and Dogs"};
	int* num_array = new int[5]{10, 20, 30, 40, 50};
	std::string* str_array = new std::string[3]{"Cat", "Dog", "Mouse"};
	std::string_view* strview_array = new std::string_view[3]{str_array[0], str_array[1], str_array[2]};

	delete num;
	delete str;
	delete[] num_array;
	delete[] str_array;
	delete[] strview_array;
}