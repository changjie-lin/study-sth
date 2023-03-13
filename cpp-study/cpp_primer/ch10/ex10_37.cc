#include <iostream>
#include <list>
#include <vector>

int main() {

	std::vector<int> iv{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::list<int> lst(iv.rbegin()+3, iv.rend()-2);

	for (auto i : lst) std::cout << i << " ";
	std::cout << std::endl;
	
	return 0;
}
