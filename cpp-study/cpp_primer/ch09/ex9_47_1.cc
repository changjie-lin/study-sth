#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main() {
	string orig{"ab2c3d7R4E6"};
	string numbers{"0123456789"};
	string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

	cout << "numeric charaters: " << endl;
	for (string::size_type pos = 0; 
	     (pos = orig.find_first_of(numbers, pos)) != string::npos; ++pos) {
		cout << orig.at(pos) << " ";
	}
	cout << endl;

	cout << "Alphabetic characters: " << endl;
	for (string::size_type pos = 0; 
	     (pos = orig.find_first_of(alphabet, pos)) != string::npos; ++pos) {
		cout << orig.at(pos) << " ";
	}
	cout << endl;

	return 0;
}
