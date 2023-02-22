#include <iostream>

using namespace std;

int main() {

	unsigned ffCnt, flCnt, fiCnt;
	char cur, next;

	cin >> cur;
	while (cin >> next) {
		if (cur == 'f') {
			switch (next) {
				case 'f':
					++ffCnt;
					break;
				case 'l':
					++flCnt;
					break;
				case 'i':
					++fiCnt;
					break;
				default:
					; // empty stmt
					break;
			}
		}
		cur = next;
	}
	cout << "'ff' Count: " << ffCnt << endl;
	cout << "'fl' Count: " << flCnt << endl;
	cout << "'fi' Count: " << fiCnt << endl;
	return 0;
}
