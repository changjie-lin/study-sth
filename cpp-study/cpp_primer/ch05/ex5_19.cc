#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

	string rsp;
	do {
		cout << "Please enter two strings: " << endl;
		string s1, s2;
		cin >> s1 >> s2;
		if (s1 == s2)
			cout << "Two strings are the same!" << endl;
		else {
			cout << (s1 < s2 ? s1 : s2) 
				<< " is less than the other." << "\n\n";
		}
		cout << "More? Enter yes or no: ";
		cin >> rsp;
	} while (!rsp.empty() && rsp[0] != 'n');
	return 0;
}
