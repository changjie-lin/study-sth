#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

std::ostream &print(std::ostream &os, const vector<string> &vs) {
	for (const auto &i : vs)
		os << i << " ";
	return os;
}

void elimDups(vector<string> &words) {

	print(cout, words) << words.size() << endl;
	
	std::sort(words.begin(), words.end());
	print(cout, words) << words.size() << endl;

	auto end_unique = std::unique(words.begin(), words.end());
	print(cout, words) << words.size() << endl;
	
	words.erase(end_unique, words.end());
	print(cout, words) << words.size() << endl;
}


int main() {
	vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the",
		"slow", "red", "turtle"};

	elimDups(words);
	return 0;
}
