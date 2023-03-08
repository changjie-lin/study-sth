#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() {
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	vector<int> iv(begin(ia), end(ia));
	list<int> il(begin(ia), end(ia));

	for (auto it = iv.begin(); it != iv.end();) {
		if (*it % 2 == 0)
			it = iv.erase(it);
		else
			++it;
	}

	for (auto it = il.begin(); it != il.end();) {
		if (*it %2 == 1)
			it = il.erase(it);
		else
			++it;
	}

	cout << "Vector values:" << endl;
	for (auto i : iv) cout << i << " ";
	cout << endl;

	cout << "List values:" << endl;
	for (auto i : il) cout << i << " ";
	cout << endl;

	return 0;
}
