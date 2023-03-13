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
	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

string make_plural(size_t count, const string &word, const string &suffix) {
	string ret(word);
	return (count > 1) ? (ret += suffix) : ret;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {

	elimDups(words);
	
	auto wc = std::partition(words.begin(), words.end(),
			         [sz](const string &a)
				      { return a.size() < sz;});


	// compute the number of elements with size >= sz
	auto count = words.end() - wc;

	cout << count << " " << make_plural(count, "word", "s")
	     << " of length " << sz << " or longer" << endl;

	// print words of the given size or longer, each one followed by a space
	for_each(wc, words.end(),
		 [](const string &s){cout << s << " ";});
	cout << endl;
	
}

int main() {
	vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the",
		"slow", "red", "turtle"};

	biggies(words, 4);

	return 0;
}
