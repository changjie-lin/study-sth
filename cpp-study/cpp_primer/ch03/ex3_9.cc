#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string one, two;
	while(getline(cin, one)) {
		two = "";
		for (auto c : one) {
			if (ispunct (c)) continue;
			two.push_back(c);
		}
		cout << two << endl;
	}
	return 0;
}
