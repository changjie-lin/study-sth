#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using std::vector;
using std::string;
using std::list;

int main() {

	vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the",
                "slow", "red", "turtle"};
	list<string> slst;

	std::sort(words.begin(), words.end());
	std::unique_copy(words.cbegin(), words.cend(), front_inserter(slst));

	for (auto s : slst) std::cout << s << " ";
	std::cout << std::endl;

	return 0;
}
