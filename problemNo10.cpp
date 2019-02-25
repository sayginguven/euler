#include <iostream>

bool isPrime(int n) {

	bool flag{ true };

	if (n < 2) return !flag;
	if (n == 2) return flag;
	if (n == 3) return flag;

	if (n > 3) {
		for (size_t i = 2; i <= sqrt(n)+1; i += 1) {
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

	int maxNum{ 2000000 };
	int startNum = 1;
	long long sum{ 0 };
	while (startNum < maxNum) {
		if (isPrime(startNum)) {
			//std::cout << "prime : " << startNum << std::endl;
			sum += startNum;
		}
		startNum += 1;
	}
	std::cout << sum << std::endl;
	
	system("pause");
	return 0;
}
