#include <iostream>
#include <string>

using namespace std;

int main() {

	string pre, cur, maxDupWord;
	int curRepCnt = 0, maxRepCnt = 0;

	while (cin >> cur) {
		if (cur == pre) {
			++curRepCnt;
		} else {
			curRepCnt = 1;
			pre = cur;
		}

		if (maxRepCnt < curRepCnt) {
			maxRepCnt = curRepCnt;
			maxDupWord = pre;
		}

	}

	if (maxRepCnt <= 1)
		cout << "No repeated word." << endl;
	else
		cout << "'" << maxDupWord << "'" << " repeats " << maxRepCnt << " times." << endl;
	return 0;
}
