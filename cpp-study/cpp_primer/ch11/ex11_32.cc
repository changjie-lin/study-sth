#include <iostream>
#include <map>
#include <string>
#include <set>

using std::string;
using std::cout;
using std::endl;

int main() {

	std::multimap<string, string> authors{
		{"Canada", "yyz"}, {"USA", "sfo"}, {"USA", "top"}, {"Canada", "toronto"},
		{"China", "beijing"}, {"China", "shanghai"}, {"Canada", "vancouver"}
	};

	std::map<string, std::set<string>> mm;
	for (const auto & a : authors)
		mm[a.first].insert(a.second);

	for (const auto &e : mm) {
		std::cout << e.first << ": ";
		for (const auto &i : e.second)
			std::cout << i << " ";
		std::cout << std::endl;
	}
	return 0;
}
