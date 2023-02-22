#include <iostream>

using namespace std;

int main() {

	int ia[10];

	for (int i = 0; i < 10; ++i) *(ia+i) = 1;

	for (int *b = begin(ia), *e = end(ia); b != e; ++b) *b = 0;

	for (auto n : ia) cout << n << " ";
	cout << endl;
	return 0;
}
