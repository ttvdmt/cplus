#include <iostream>

int cube(int& n){
	return n*n*n;
}

int main(){
	int n = 2;
	std::cout << cube(n);
}