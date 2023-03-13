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

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}


int main() {
	vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the",
		"slow", "red", "turtle"};

	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);
	print(cout, words) << words.size() << endl;
	return 0;
}
