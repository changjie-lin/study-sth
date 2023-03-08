/*
 * list does not support iterator arithmetic
 *
 * */

#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;


int main() {

	list<int> lst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = lst.begin();
	while (iter != lst.end()) {

		if (*iter % 2) {
			iter = lst.insert(iter, *iter);
			std::advance(iter, 2);
		} else
			iter = lst.erase(iter);
	}

	for (auto i : lst) cout << i << " ";
	cout << endl;

	return 0;
}
