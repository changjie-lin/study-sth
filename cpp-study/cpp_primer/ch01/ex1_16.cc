#include <iostream>
using namespace std;

int main() {
	cout << "Enter some numbers:" << endl;
	int sum = 0, val = 0;
	while(cin >> val)
		sum += val;

	cout << "Sum is: " << sum << endl;
	return 0;
}
