#include <iostream>
#include <algorithm>

int main() {

	int num;
	auto isZero = [&num] () -> bool {
		if (num == 0) return true;
		--num;
		return false;
	};
	
	std::cout << "Input a integer (>0): ";
	std::cin >> num;

	while (!isZero()) std::cout << num << std::endl;
	return 0;
}
