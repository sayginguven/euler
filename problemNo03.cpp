//The prime factors of 13195 are 5, 7, 13 and 29.
//
//What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <time.h>
#include <stack>

bool isPrime(int n) {

	bool flag{ true };

	if (n < 2) return !flag;
	if (n == 2) return flag;
	if (n == 3) return flag;

	if (n > 3) {
		for (size_t i = 2; i <= sqrt(n) + 1; i += 1) {
			if (n % i == 0) {
				flag = false;
				return flag;
			}
		}
		if (flag)
			return flag;
	}
}

int main() {
	long long number = 600851475143;
	std::stack<int> primeNumbers;

	for (size_t i = 2; i < (sqrt(number)+1); i+=1 )
	{
		if (isPrime(i)) {
			primeNumbers.push(i);
		}
	}

	while (number % primeNumbers.top()!= 0) {
		primeNumbers.pop();
	}

	std::cout << "largest prime factor of the number is : " << primeNumbers.top() << std::endl;

	system("pause");
	return 0;
}