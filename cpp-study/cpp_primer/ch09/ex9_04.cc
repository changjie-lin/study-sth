#include <iostream>
#include <vector>

using std::vector;
using citer = vector<int>::const_iterator;

bool containsVal(citer bg, citer ed, int val) {
	for (auto it = bg; it != ed; ++it)
		if (*it == val)
			return true;

	return false;
}

int main() {
	int num;
	std::cout << "Input a number: ";
	std::cin >> num;
	
	vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	if (containsVal(vec.cbegin(), vec.cend(), num))
		std::cout << "Yes, it contains.";
	else
		std::cout << "No, not contained.";
	std::cout << std::endl;
	return 0;
}
