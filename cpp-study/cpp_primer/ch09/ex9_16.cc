#include <iostream>
#include <list>
#include <vector>

int main() {

	std::vector<int> v1{1, 2, 3, 4, 5};
	std::vector<int> v2{1, 2, 8};
	std::list<int> lst{1, 2, 8};

	std::cout << std::boolalpha
		  << (std::vector<int>(lst.begin(), lst.end()) == v1)
		  << std::endl;
	std::cout << std::boolalpha
		  << (std::vector<int>(lst.begin(), lst.end()) == v2)
		  << std::endl;
	return 0;
}
