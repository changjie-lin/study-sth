#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using std::list;
using std::string;
using std::cout;
using std::endl;

std::ostream &print(std::ostream &os, const list<string> &vs) {
	for (const auto &i : vs)
		os << i << " ";
	return os;
}

void elimDups(list<string> &words) {

	print(cout, words) << words.size() << endl;
	
	//std::sort(words.begin(), words.end());
	words.sort();
	print(cout, words) << words.size() << endl;

	//auto end_unique = std::unique(words.begin(), words.end());
	words.unique();
	print(cout, words) << words.size() << endl;
	
	//words.erase(end_unique, words.end());
	//print(cout, words) << words.size() << endl;
}


int main() {
	list<string> words{"the", "quick", "red", "fox", "jumps", "over", "the",
		"slow", "red", "turtle"};

	elimDups(words);
	return 0;
}
