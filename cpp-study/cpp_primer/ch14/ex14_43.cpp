#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	auto data = {2, 3, 5, 7, 11};
	int input;
	std::cout << "Input: ";
	std::cin >> input;

	auto is_divisible = std::any_of(data.begin(), data.end(),
		[&input](int divisor)
			{ return 0 == std::modulus<int>()(input, divisor); });
	std::cout << (is_divisible ? "Yes" : "No") << std::endl;
}
