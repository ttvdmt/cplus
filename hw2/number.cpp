#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <memory.h>

class Number 
{
private:
    static const int base = 100;
    std::size_t size;
    std::size_t capacity;
    char* data;

public:
	Number()
	{
		capacity = 1;
		data = new char[capacity];
		data[0] = 0;
		size = capacity;
	}
	Number(const Number& n)
	{
		size = n.size;
		capacity = n.capacity;
		std::swap(data, n.data);
	}
}
