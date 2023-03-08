/*
 * changes on forward_list
 *
 * 1. vi.insert -> vi.insert_after
 * 2. iter += 2 -> advance(iter, 2)
 * 3. vi.erase  -> vi.erase_after
 * 4. add iterator prev
 * */

#include <iostream>
#include <forward_list>

using std::cout;
using std::endl;
using std::forward_list;


int main() {

	forward_list<int> lst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = lst.begin(), prev = lst.before_begin();
	while (iter != lst.end()) {

		if (*iter % 2) {
			iter = lst.insert_after(prev, *iter);
			std::advance(iter, 2);
			std::advance(prev, 2);
		} else
			iter = lst.erase_after(prev);
	}

	for (auto i : lst) cout << i << " ";
	cout << endl;

	return 0;
}
