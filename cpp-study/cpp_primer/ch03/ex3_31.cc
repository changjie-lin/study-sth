#include <iostream>

using namespace std;

int main() {

	int arr[10];
	for (int i = 0; i < 10; i++) arr[i] = i;

	for (auto j : arr) cout << j << " ";

	cout << endl;
	return 0;
}
