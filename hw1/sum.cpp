#include <iostream>

void countLetters(const char* str, int& numLetters, int& numDigits, int& numOther){
	for(int i = 0; str[i] != 0; i++){
		if(str[i] >= '0' && str[i] <= '9'){
			numDigits++;
		}
		else if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')){
			numLetters++;
		}
		else{
			numOther++;
		}
	}
}

int main(){
	char str[100];
	std::cin >> str;
	int numLetters = 0;
	int numOther = 0;
	int numDigits = 0;
	countLetters(str, numLetters, numDigits, numOther);
	std::cout << numLetters << std::endl << numDigits << std::endl << numOther;
}