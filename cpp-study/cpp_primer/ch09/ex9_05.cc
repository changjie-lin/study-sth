#include <iostream>
#include <vector>

using std::vector;
using citer = vector<int>::const_iterator;

citer containsVal(citer bg, citer ed, int val) {
	for (auto it = bg; it != ed; ++it)
		if (*it == val)
			return it;

	return ed;
}

int main() {
	int num;
	std::cout << "Input a number: ";
	std::cin >> num;
	
	vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto it = containsVal(vec.cbegin(), vec.cend(), num);
	if (it == vec.end())
		std::cout << "No, not contained.";
	else
		std::cout << "Yes, it contains the value at position "
			  << it - vec.begin();
	std::cout << std::endl;
	return 0;
}
