#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	while(getline(cin, input)) {
	/*	for (auto &c : input)
			c = 'x';
	*/
		decltype(input.size()) i = 0;
		while (i < input.size()) {
			input[i] = 'X';
			i++;
		}
		cout << input << endl;
		
		for (decltype(input.size()) index = 0; index != input.size(); ++index)
			input[index] = 'Y';

		cout << input << endl;
	}
	return 0;
}
