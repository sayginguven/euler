//A palindromic number reads the same both ways.The largest palindrome made from the product of two 2 - digit numbers is 9009 = 91 × 99.
//
//Find the largest palindrome made from the product of two 3 - digit numbers.

#include <iostream>
#include <time.h>
int reverseNumber(int num) {//25

	int i{ 0 };
	int reversedNum{ 0 };
	int digit{ 0 };

	//find the digit count for the number
	while (static_cast<int>(num / pow(10, i)) > 0) {
		digit += 1;
		i += 1;
	}
	i = 0;

	//reverse and add the number to reversed number
	while (static_cast<int>(num / pow(10, i)) > 0) {
		int temp = static_cast<int>(num / pow(10, i)) % 10;
		reversedNum += temp* pow(10, (digit - 1));
		digit -= 1;
		i += 1;
	}
	return reversedNum;

}

bool isPalindrome(int num) {
	if (num == reverseNumber(num))
		return true;
	return false;
}

bool isProductOf3Digit(int num) {

	int i = 999;
	while (num % i!= 0) {
		if (i < 100) {
			break;
		}
		i -= 1;
	}

	if ((num % i)== 0 && num/i <1000) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	int i = 999 * 999;

	while (!isPalindrome(i)) {
		i -= 1;
		if (isPalindrome(i) && !isProductOf3Digit(i)) {
			i -= 1;
		}
	}

	std::cout << "palindrome is " << i << std::endl;



	system("pause");
	return 0;
}