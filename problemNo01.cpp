//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//
//Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>
#include <time.h>

int multipliersSum1(int a, int b, int number) {
	int sum{ 0 };
	for (size_t i = 0; i < number; i++)
	{
		if (i%a == 0 || i %b == 0) {
			sum += i;
		}
	}
	return sum;
}

int multiplierSum2(int a, int b, int number) {
	int sum{ 0 };
	for (size_t i = 0; i < number; i += a)
	{
		if (i % b != 0) {
			sum += i;
		}
	}
	for (size_t i = 0; i < number; i += b)
	{
		sum += i;
	}
	return sum;
}

int main() {

	double start = clock();
	std::cout << multipliersSum1(3, 5, 1000) << std::endl;
	double end = clock();
	std::cout << "multipliersSum1 takes "
		<< (end - start) / CLOCKS_PER_SEC << "seconds."
		<< std::endl;

	start = clock();
	std::cout << multiplierSum2(3, 5, 1000) << std::endl;
	end = clock();
	std::cout << "multipliersSum2 takes "
		<< (end - start) / CLOCKS_PER_SEC << "seconds."
		<< std::endl;


	system("pause");
	return 0;
}