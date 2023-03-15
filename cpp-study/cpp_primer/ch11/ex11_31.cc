#include <iostream>
#include <map>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main() {

	std::multimap<string, string> authors{
		{"Canada", "YYZ"}, {"USA", "SFO"}, {"USA", "TOP"}, {"Canada", "toronto"},
		{"China", "Beijing"}, {"China", "Shanghai"}, {"Canada", "Vancouver"}
	};

	string author{"USA"}, work{"SFO"};

	for (auto found = authors.find(author);
	     found != authors.end() && found->first == author;) {

		if (found->second == work)
			found = authors.erase(found);
		else
			++found;
	}

	for (const auto & a : authors)
		std::cout << a.first << " " << a.second << std::endl;
	return 0;
}
