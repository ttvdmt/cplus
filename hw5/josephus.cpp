#include <iostream>
#include <list>
#include <iterator>

std::list<int> add(int n)
{
	std::list<int> l;
	for (int i = 1; i < n + 1; i++)
	{
		l.push_back(i);
	}
	return l;
}

std::list<int>::iterator true_next(std::list<int>::iterator it, std::list<int>& l, int m)
{
	for (int i = 0; i < m; i++)
	{
		if (*it != l.back()) 
			it = std::next(it);

		else 
			it = l.begin();
	}
	return it;
}

std::list<int>::iterator true_prev(std::list<int>::iterator it, std::list<int>& l)
{
	if (it == l.begin()) 
		it = std::prev(l.end());

	else 
		it = std::prev(it);
	
	return it;
}

void josephus(std::list<int>& l, int m)
{
	std::list<int>::iterator it = l.begin();
	while (l.size() != 1)
	{
		it = true_next(it, l, m);
		std::cout << *(true_prev(it, l)) << ' ';
		l.erase(true_prev(it, l));
	}
	std::cout << std::endl << *(l.begin()) << std::endl;
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	std::list<int> nums = add(n);
	josephus(nums, m);
}