#include <iostream>
#include <string>

using namespace std;

int main() {
	string sum, str;

	while (cin >> str) {
		sum += str;
	}

	cout << "The concatenated string is: " << sum << endl;
	return 0;
}
