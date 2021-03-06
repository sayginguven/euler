//Each new term in the Fibonacci sequence is generated by adding the previous two terms.By starting with 1 and 2, the first 10 terms will be :
//
//1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//
//By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even - valued terms.

#include <iostream>
#include <time.h>

int fibonnaci(int n) {

	if (n == 1)return 1;

	if (n == 2)return 2;

	if (n > 2) {
		return fibonnaci(n-2) + fibonnaci(n - 1);
	}
}

int main() {

	double start = clock();
	int n = 1;
	long long int sum1{ 0 };
	while (fibonnaci(n) < 4000000)
	{
		if (fibonnaci(n) % 2 == 0) {
			sum1 += fibonnaci(n);
		}
		n += 1;
	}
	std::cout << "checking all fibonacci series and adding only even numbers: " << sum1 << std::endl;
	double end = clock();
	std::cout << "it takes: " << (end - start) / CLOCKS_PER_SEC << " seconds\n\n";

	start = clock();
	int sum2{ 0 };
	for (size_t i = 2; fibonnaci(i)<4000000; i+=3)
	{
		sum2 += fibonnaci(i);
	}
	std::cout << "adding only even fibonacci numbers : " << sum2 << std::endl;
	end = clock();
	std::cout << "it takes: " << (end - start) / CLOCKS_PER_SEC << sum2 << " seconds\n\n";
	
	
	system("pause");
	return 0;
}