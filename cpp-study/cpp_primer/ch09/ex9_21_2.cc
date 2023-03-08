#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
	vector<string> lst;
	auto iter = lst.begin();
	string word;
	while (cin >> word)
		iter = lst.insert(iter, word);

	for (auto &s : lst)
		cout << s << endl;

	return 0;
}
