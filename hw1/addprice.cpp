#include <iostream>

struct Book{
	char title[100];
	int pages;
	float price;
};

void addprice(Book& book, float& x){
	book.price += x;
}

int main(){
	float x = 5.2;
	Book b = {"War and Peace", 1200, 900};
	addprice(b, x); 
	std::cout << b.price;
}