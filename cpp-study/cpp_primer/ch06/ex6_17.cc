#include <iostream>
#include <string>

using std::string;

bool hasUpperCase(const string& str) {
	for (auto c : str)
		if (isupper(c))
			return true;

	return false;
}

void toLowerCase(string& str) {
	for (auto& c : str)
		if (isupper(c))
			c = tolower(c);
}

int main() {
	string s;
	std::cout << "Pls input a string: " << std::endl;
	getline(std::cin, s);
	if (hasUpperCase(s)) {
		std::cout << "It contains the upper case letters. \n"
			  << "The lower case version: \n";
		toLowerCase(s);
		std::cout << s << std::endl;
	} else
		std::cout << "It does not contain upper case letters.";

	std::cout << std::endl;

}
