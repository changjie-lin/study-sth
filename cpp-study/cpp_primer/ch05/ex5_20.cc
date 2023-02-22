#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

	string prev, curr;
	bool found = false;

	while (cin >> curr)
		if (curr == prev) {
			found = true;
			break;
		} else {
			prev = curr;
		}

	if (found)
		cout << curr << " occurs twice in succession." << endl;
	else
		cout << "no word was repeated." << endl;
	return 0;
}
