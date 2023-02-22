#include <iostream>

using namespace std;

int main() {

	unsigned vowelCnt = 0;
	char ch;

	while (cin >> ch) {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			++vowelCnt;
	}
	cout << "Vowel Count: " << vowelCnt << endl;
	return 0;
}
