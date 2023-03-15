#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {

	vector<string> exclude{"aa", "bb", "cc"};
	for (string word; std::cin >> word;) {
		if (std::find(exclude.begin(), exclude.end(), word) != exclude.end())
			cout << "excluded!" << endl;
		else
			exclude.push_back(word);
	}

	for (auto const &s : exclude) cout << s << " ";
	cout << endl;

	return 0;
}
