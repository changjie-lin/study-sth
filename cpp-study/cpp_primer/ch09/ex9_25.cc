/*
 * If elem1 and elem2 are equal, no elements would be erased.
 *
 * If elem2 is the off-the-end iterator, all elements are erased.
 *
 * If both elem1 and elem2 are the off-the-end iterator, no elements is removed.
 * */

#include <iostream>
#include <list>


using std::list;
using std::cout;

int main() {
	list<int> lst{1, 2, 3};

	auto elem1 = lst.begin();
	auto elem2 = ++elem1;

	elem1 = lst.erase(elem1, elem2);

	for (auto &i : lst) cout << i << std::endl;

	return 0;
}
