#include <iostream>

int getLarger(int a, const int* const ptr) {
	return (a > *ptr) ? a : *ptr;
}

int main() {

	std::cout << "Input two integer numbers: " << std::endl;
	int a, b;
	std::cin >> a >> b;
	std::cout << "The larger one is " << getLarger(a, &b) << std::endl;
	return 0;
}
