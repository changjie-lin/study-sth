#include <iostream>

using namespace std;

int main() {

	int arr[10];
	for (int i = 0; i < 10; i++) arr[i] = i;

	int ia [10];
	for (size_t i = 0; i < 10; ++i) ia[i] = arr[i];

	// use vector
	vector<int> iv(10);
	for (auto it.begin(); it != iv.end(); ++it)
		*it = it - it.begin();

	vector<int> iv2(iv);

	for (auto j : iv2) cout << j << " ";
	cout << endl;

	return 0;
}
