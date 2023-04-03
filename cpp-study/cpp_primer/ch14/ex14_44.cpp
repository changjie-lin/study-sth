#include <iostream>
#include <string>
#include <map>
#include <functional>

int add(int i, int j) { return i + j; }

auto mod = [](int i, int j) { return i % j; };

struct divide {
	int operator()(int denominator, int divisor) {
		return denominator / divisor;
	}
};

std::map<std::string, std::function<int(int, int)>> binops = {
	{"+", add},
	{"-", std::minus<int>()},
	{"/", divide()},
	{"*", [](int i, int j) { return i * j; }},
	{"%", mod}
};

int main()
{
	while(true) {
		std::cout << "\nPlease enter in formats: number operator number: \n";
		int n1, n2;
		std::string s;

		std::cin >> n1 >> s >> n2;
		std::cout << "\nResult = " << binops[s](n1, n2);
	}
	return 0;
}
