#include <iostream>

int main() {

	int a, b;

	std::cout << "Input two integers: ";
	while (std::cin >> a >> b) {
		try {
			if (b == 0) throw std::runtime_error("divide by 0");
			std::cout << a/b << std::endl;
			std::cout << "Input two integers: " << std::endl;
		} catch (std::runtime_error& err) {
			std::cout << err.what()
			     << " \nTry Again? Enter y or n" << std::endl;
			char c;
			std::cin >> c;
			if (!std::cin || c == 'n')
				break;
			else
				std::cout << "Input two integers: " << std::endl;
		}
	}
	return 0;
}
