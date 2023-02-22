#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(const vector<int> &vec) {
	for (auto it = vec.cbegin(); it != vec.cend(); ++it) cout << *it << " ";

	cout << endl;
}

void print(const vector<string> &vec) {
	for (auto it = vec.cbegin(); it != vec.cend(); ++it) cout << *it << " ";

	cout << endl;
}


int main() {

	vector<int> v1;               // 0  element
  	vector<int> v2(10);           // 10 elements, values are all 0
  	vector<int> v3(10, 42);       // 10 elements, values are all 42
  	vector<int> v4{10};           // 1  element,  value  is  10
  	vector<int> v5{10, 42};       // 2  elements, values are 10 and 42
  	vector<string> v6{10};        // 10 elements, values are all empty string
  	vector<string> v7{10, "hi"};  // 10 elements, values are all "hi"

	print(v1);
	print(v2);
	print(v3);
	print(v4);
	print(v5);
	print(v6);
	print(v7);
	return 0;
}
