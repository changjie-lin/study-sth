#include <iostream>
using namespace std;

int main() {
	int head, tail;
	cout << "Please input two numbers:" << endl;
	cin >> head >> tail;
	int val = head + 1;
	while (val < tail) {
		cout << val << endl;
		val++;
	}
	return 0;
}
