#include <iostream>

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {

	int a, b;
	std::cout << "Enter two ints: ";
	std::cin >> a >> b;
	swap(a, b);
	std::cout << "The swapped values: " << a << " " << b << std::endl;
	return 0;
}
