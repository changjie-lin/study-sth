#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class SizeComp {
public:
	SizeComp(size_t n) : sz(n) { }
	bool operator()(const string &s) const
		{ return s.size() < sz; }
private:
	size_t sz;
};

class PrintString {
public:
	PrintString(std::ostream &o = std::cout, char c = ' ') :
		os(o), sep(c) { }
	void operator()(const std::string &s) const { os << s << sep; }
private:
	std::ostream &os;
	char sep;
};


void elimDups(vector<string> &words) {
	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

string make_plural(size_t count, const string &word, const string &suffix) {
	string ret(word);
	return (count > 1) ? (ret += suffix) : ret;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {

	elimDups(words);
	/*
	auto wc = std::stable_partition(words.begin(), words.end(),
			         [sz](const string &a)
				      { return a.size() < sz;});
	*/
	auto wc = std::stable_partition(words.begin(), words.end(), SizeComp(sz));


	// compute the number of elements with size >= sz
	auto count = words.end() - wc;

	cout << count << " " << make_plural(count, "word", "s")
	     << " of length " << sz << " or longer" << endl;

	// print words of the given size or longer, each one followed by a space
	// for_each(wc, words.end(),
	//	 [](const string &s){cout << s << " ";});
	PrintString printer;
	for_each(wc, words.end(), printer);
	cout << endl;
	
}

int main() {
	vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the",
		"slow", "red", "turtle"};

	biggies(words, 4);

	return 0;
}
