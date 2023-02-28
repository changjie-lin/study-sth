#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact(int val) {
	int result = 1;
	while (val > 1) result *= val--;
	return result;
}

void ask() {
	unsigned int val;
	cout << "Please enter a number with [0, 12]: ";
	cin >> val;
	cout << val << "! = " << fact(val) << endl;
}

int main() {
	ask();
	return 0;
}
