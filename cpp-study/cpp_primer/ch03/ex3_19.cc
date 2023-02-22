#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> ivec1{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
	vector<int> ivec2;
    	for (int i = 0; i != 10; ++i) ivec2.push_back(42);

	vector<int> ivec3(10, 42);


	cout << "ivec1{42, 42, 42, 42, 42, 42, 42, 42, 42, 42}:" << endl;
	for (auto i : ivec1) {
		cout << i << " ";
	}
	cout << "\b" << endl;
	
        cout << "ivec2 intialized with for loop:" << endl;
	for (auto i : ivec2) {
                cout << i << " ";
        }
	cout << "\b" << endl;
	
        cout << "ivec3(10, 42):" << endl;
	for (auto i : ivec3) {
                cout << i << " ";
        }
        cout << "\b" << endl;

	return 0;
}
