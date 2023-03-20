#include <iostream>

int main() {

	std::cout << "Input string length: ";
	size_t len;
	std::cin >> len;
	std::cin.ignore();

	char *input = new char[len + 1];
	std::cin.get(input, len + 1);
	std::cout << "The input string is: \n" << input << std::endl;
	return 0;
}
