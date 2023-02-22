#include <iostream>
#include <vector>

using namespace std;

int main() {

	int ia[] = {0, 1, 2, 3};
	vector<int> iv(begin(ia), end(ia));

	for (auto i : iv) cout << i << " ";
	cout << endl;
	return 0;
}
