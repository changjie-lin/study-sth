#include <iostream>


template <typename T>
T abs(T i)
{
    return i >= 0 ? i : -i;
}

int main() {
	std::cout << "Enter a number: ";
	double val;
	std::cin >> val;
	std::cout << "The absolute value is " << abs(val) << std::endl;
	return 0;
}
