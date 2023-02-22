#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (auto& i : vec) i = (i % 2) ? (i * 2) : i;

	for (auto i : vec) cout << i << " ";
	cout << endl;
	return 0;
}
