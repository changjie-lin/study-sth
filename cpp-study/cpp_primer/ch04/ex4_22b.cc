#include <iostream>

using namespace std;

int main() {

	string finalgrade;
	unsigned grade;

	while (cin >> grade) {
		if (grade > 90) {
			finalgrade = "high pass";
		} else if (grade <= 75 && grade >= 60) {
			finalgrade = "low pass";
		} else if (grade < 60) {
			finalgrade = "fail";
		} else {
			finalgrade = "pass";
		}

		cout << finalgrade << endl;
	}
	return 0;
}
