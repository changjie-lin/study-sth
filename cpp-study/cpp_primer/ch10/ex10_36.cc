#include <iostream>
#include <list>
#include <algorithm>

std::ostream &findZero(std::ostream &os, const std::list<int> &lst) {
	auto end_find = std::find(lst.crbegin(), lst.crend(), 0);
	if (end_find == lst.crend())
		os << "Not found zero in this list.";
	else
		os << "Found zero in front of " << *end_find.base();
	
	return os;
}


int main() {

	std::list<int> one{1, 2, 3, 4, 5};
	findZero(std::cout, one) << std::endl;

	std::list<int> two{1, 2, 0, 3, 4, 5};
	findZero(std::cout, two) << std::endl;
	
	return 0;
}
