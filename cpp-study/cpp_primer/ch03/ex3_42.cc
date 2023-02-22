#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> ivec{1, 2, 3, 4, 5};
	int ia[5];
	for (int i = 0; i < 5; ++i)
		ia[i] = ivec[i];

	for (auto j : ia) cout << j << " ";
	cout << endl;
	return 0;
}
