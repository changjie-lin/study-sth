#include <iostream>

void swap(int*& p1, int*& p2) {
	auto tmp = p1;
	p1 = p2;
	p2 = tmp;
}

int main() {
	std::cout << "Input two integer numbers: ";
	int a, b;
	std::cin >> a >> b;
	int *p1 = &a, *p2 = &b;
	swap(p1, p2);
	std::cout << "After swapping: " << *p1 << " " << *p2 << std::endl;

	return 0;
}
