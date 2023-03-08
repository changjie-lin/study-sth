#include <iostream>
#include <list>
#include <string>

using std::string;
using std::list;

int main() {

	list<string> lst;
	auto iter = lst.begin();
	while (cin >> word)
		iter = lst.insert(iter, word);

	for (auto &s : lst) std::cout << s << std::endl;
	return 0;
}
