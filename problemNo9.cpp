//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//
//	a^2 + b^2 = c^2
//	For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
//
//	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//	Find the product abc.
//
#include <iostream>
#include <chrono>
#include <thread>

void slowSolution() {
	bool option1{ false };
	int a{ 1 };
	int b{ 2 };
	int c = 1000 - (a + b);

	while (!option1) {

		c = 1000 - (a + b);

		if ((pow(a, 2) + pow(b, 2)) == pow(c, 2)) {
			std::cout << "special triangle " << a << ", " << b << ", " << b << std::endl;
			long result = a * b * c;
			std::cout << "product of a b c is: " << result << std::endl;
			option1 = true;
		}
		else {
			std::cout << "combination of " << a << " " << b << " " << c << " failed! " << std::endl;
			b += 1;
		}

		//loop
		// 1 2 3
		// 1 2 4
		// 1 2 5
		if (b > c) {
			a += 1;
			b = a + 1;
		}
	}
}
void fastSolution() {
	//faster way
	bool option2{ false };
	int a{ 1 };
	int b{ 2 };
	double c = sqrt(pow(a, 2) + pow(b, 2));
	int counter = 0;

	while (!option2) {

		c = sqrt(pow(a, 2) + pow(b, 2));


		//check if the c is integer
		if ((c - static_cast<int>(c)) != 0) {
			b += 1;
		}

		if ((c - static_cast<int>(c)) == 0) {

			if (1000 % (a + b + static_cast<int>(c)) == 0) {
				a *= (1000 / (a + b + static_cast<int>(c)));
				b *= (1000 / (a + b + static_cast<int>(c)));
				c *= (1000 / (a + b + static_cast<int>(c)));

				if (a + b + c == 1000) {
					std::cout << "special triangle " << a << ", " << b << ", " << b << std::endl;
					long result = a * b * c;
					std::cout << "product of a b c is: " << result << std::endl;
					option2 = true;
				}
			}
			//std::cout << "special triangle " << a << ", " << b << ", " << b << std::endl;
			b += 1;
		}

		if (b > a * 5) {
			a += 1;
			b = a + 1;
		}
	}
}

int main() {

	std::cout << "slow solution " << std::endl;
	slowSolution();
	std::cout << "__ __ __ __ __ __ __ __ __" << std::endl;
	std::cout << "fast solution " << std::endl;
	fastSolution();

	system("pause");
	return 0;
}
