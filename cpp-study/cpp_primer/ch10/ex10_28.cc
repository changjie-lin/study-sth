#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::cout;
using std::endl;

void print(list<int> &v) {
	for (int i : v) cout << i << " ";
	cout << endl;
}

int main() {

	vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

	list<int> v1, v2, v3;
	copy(vec.cbegin(), vec.cend(), back_inserter(v1));
	print(v1);

	copy(vec.cbegin(), vec.cend(), front_inserter(v2));
	print(v2);

	copy(vec.cbegin(), vec.cend(), inserter(v3, v3.begin()));
	print(v3);


	return 0;
}
