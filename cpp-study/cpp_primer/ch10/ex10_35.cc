#include <iostream>
#include <vector>

int main() {

	std::vector<int> iv{1, 2, 3, 4, 5};
	for (auto it = iv.cend(); it != iv.cbegin();)
		std::cout << *--it << " ";

	std::cout << std::endl;
	return 0;
}
