#include <iostream>

struct Book{
	char title[100];
	int pages;
	float price;
};

bool isExpensive(const Book& book){
	return book.price < 1000;
}

int main(){
	Book b = {"War and Peace", 1200, 900};
	std::cout << isExpensive(b);
}