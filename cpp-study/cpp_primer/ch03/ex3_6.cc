#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	while(getline(cin, input)) {
		for (auto &c : input)
			c = 'x';
		cout << input << endl;
	}
	return 0;
}
