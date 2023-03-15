#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::map;
using std::cout;
using std::endl;
using std::vector;

using familyType = std::map<std::string, 
      			    std::vector<std::pair<std::string, std::string>>>;

void addFamily(familyType &families, const string &lastName) {
	auto ret = families.insert({lastName, vector<std::pair<string, string>>()});
	if (!ret.second)
		std::cerr << "It already contain this family: "
			  << lastName << endl; 
}

void addChild(familyType &families, 
	      const string &lastName,
	      const string &firstName,
	      const string &birthday) {
	auto it = families.find(lastName);
	if (it != families.end()) {
		it-> second.push_back({firstName, birthday});
	} else
		std::cerr << "This family: " << lastName << " is not included yet."
		          << endl;
}

int main() {
	
	familyType families;

	addFamily(families, "Jones");
	addFamily(families, "Smith");
	
	addFamily(families, "Jones"); // error: duplicate family name

	addChild(families, "Jones", "Noah", "1960-5-1");
	addChild(families, "Jones", "Chris", "1970-6-1");
	addChild(families, "Smith", "Adam", "1980-7-1");


	addChild(families, "Hawk", "Ethan", "1971-9-1"); // error: this family is not in
	for (const auto &fam : families)
		for (const auto &child : fam.second)
			cout << fam.first << ", " << child.first << " "
			     << child.second << endl;

	return 0;
}
