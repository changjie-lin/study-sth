#include <iostream>
#include <list>
#include <string>

using std::list;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
	list<string> lst;
	auto iter = lst.begin();
	string word;
	while (cin >> word)
		iter = lst.insert(iter, word);

	for (auto &s : lst)
		cout << s << endl;

	return 0;
}
