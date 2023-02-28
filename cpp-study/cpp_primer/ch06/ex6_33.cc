#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using Iter = vector<int>::iterator;

void print(Iter cur, Iter ed) {

	if (cur != ed) {
		cout << *cur << " ";
		print(++cur, ed);
	}
}

int main() {
	vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print(vec.begin(), vec.end());
	return 0;
}
