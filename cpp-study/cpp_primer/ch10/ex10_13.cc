#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;


bool overFive(const string &s) {
	return s.size() >= 5;
}

int main() {
	vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the",
		"slow", "red", "turtle"};

	auto end_partition = std::partition(words.begin(), words.end(), overFive);

	for (auto it = words.begin(); it != end_partition; ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}
