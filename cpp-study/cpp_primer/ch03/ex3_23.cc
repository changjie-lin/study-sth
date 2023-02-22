#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> v(10, 1);

	for (auto it = v.begin(); it != v.end(); ++it) *it *= 2;
	for (auto value : v) cout << value << " ";
	
	cout << endl;

	return 0;
}
