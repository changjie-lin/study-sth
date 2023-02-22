#include <iostream>
#include <vector>

using namespace std;

int main() {

	int a1[] = {0, 1, 2};
	int a2[] = {0, 1, 2};

	int size1 = sizeof(a1) / sizeof(a1[0]);
	int size2 = sizeof(a2) / sizeof(a2[0]);

	bool isEqualArray = true;
	if (size1 != size2) {
		isEqualArray = false;
	} else {
		for (int i = 0; i < size1; ++i) {
			if (a1[i] != a2[i]) {
				isEqualArray = false;
				break;
			}
			isEqualArray = true;
		}
	}

	if (isEqualArray)
		cout << "The two arrays are equal." << endl;
	else
		cout << "The two arrays are not equal." << endl;

	// =====================
	vector<int> v1 = {1, 2, 3, 4};
	vector<int> v2 = {1, 2, 3, 4};
	
	if (v1 == v2)
		cout << "The two vectors are euqal." << endl;
	else
		cout << "The two vectors are not equal." << endl;

	return 0;
}
