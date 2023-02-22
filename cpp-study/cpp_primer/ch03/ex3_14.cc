#include <iostream>
#include <vector>

using namespace std;

int main() {
	int i;
	vector<int> ivec;
	while (cin >> i) ivec.push_back(i);

	for (auto i: ivec)
		cout << i << " ";

	cout << endl;
	return 0;
}
