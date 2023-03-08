#include <iostream>
#include <vector>

int main() {
	std::vector<int> v1{1, 2, 3, 4, 5}, v2(v1), v3{1, 2, 8};

	std::cout << std::boolalpha << (v2 == v1) << std::endl;
	std::cout << std::boolalpha << (v3 == v1) << std::endl;

	return 0;
}
