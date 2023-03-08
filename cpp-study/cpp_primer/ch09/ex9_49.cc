#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;

int main() {

	ifstream ifs("../data/letter.txt");
	if (!ifs) {
		std::cerr << "Could not open file!" << std::endl;
		return -1;
	}

	string longest_word;
	string ascenderDescender{"aceimnorsuvwxz"};
	for (string word; ifs >> word;)
		if (word.find_first_not_of(ascenderDescender) == string::npos &&
		    word.size() > longest_word.size())
			longest_word = word;

	if (longest_word.empty())
		std::cout << "There is no such word that contains neither ascenders nor descenders" << std::endl;
	else
		std::cout << longest_word << std::endl;

	return 0;
}
