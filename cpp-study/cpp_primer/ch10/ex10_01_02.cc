#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

int main() {

	// ex 1
	std::vector<int> v{1, 2, 3, 4, 5, 6, 6, 2, 6};
	std::cout << "'6' appears " << std::count(v.cbegin(), v.cend(), 6) 
		  << " times."<< std::endl;

	// ex 2
	std::list<std::string> lst{"ni", "hao", "ma", "hao", "?"};
	std::cout << "\"hao\" appears " << std::count(lst.cbegin(), lst.cend(), "hao")
		  << " times." << std::endl;
	return 0;
}
