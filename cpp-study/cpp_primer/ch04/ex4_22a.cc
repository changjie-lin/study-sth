#include <iostream>

using namespace std;

int main() {

	string finalgrade;
	unsigned grade;

	while (cin >> grade) {
		finalgrade = (grade > 90) ? "high pass"
		: ( (grade <= 75) && (grade >= 60) ) ? "low pass"
		: (grade < 60) ? "fail" : "pass";

		cout << finalgrade << endl;
	}
	return 0;
}
