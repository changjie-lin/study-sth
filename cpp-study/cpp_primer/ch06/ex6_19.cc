#include <iostream>

using std::string;

int count(const string &, char);

int main() {
	int c = count("abcda", 'a');
	std::cout << c << std::endl;
	return 0;
}

int count(const string &str, char ch) {
	
	int num = 0;
	for (auto c : str)
		if (c == ch) ++num;

	return num;
}
