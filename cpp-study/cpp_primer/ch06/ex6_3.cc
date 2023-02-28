#include <iostream>

int fact(int val) {

	if (val == 0 || val == 1)
		return 1;
	else
		return val * fact(val - 1);
}

int main() {

	int val;
	std::cout << "Enter a number: ";
	std::cin >> val;
	std::cout << "The factorial is " << fact(val) << std::endl;
	return 0;
}
