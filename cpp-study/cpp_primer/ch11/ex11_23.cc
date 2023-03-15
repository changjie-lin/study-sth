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

using familyType = std::multimap<std::string, std::vector<std::string>>;


void addFamily(familyType &families, const string &lastName) {
	families.insert({lastName, std::vector<std::string>()});
	/*
	auto ret = families.insert({lastName, vector<string>()});
	if (!ret.second)
		std::cerr << "It already contain this family: "
			  << lastName << endl; 
	*/
}

void addChild(familyType &families, const string &lastName, const string &firstName) {
	auto it = families.find(lastName);
	if (it != families.end()) {
		auto iter = std::find(it->second.cbegin(), it->second.cend(), 
				firstName);
		if (iter == it->second.cend())
			it -> second.push_back(firstName);
		else
			std::cerr << "This child, " << firstName << " is already in"
				  << endl;
	} else
		std::cerr << "This family: " << lastName << " is not included yet."
		          << endl;
}

int main() {
	
	familyType families;

	addFamily(families, "Jones");
	addFamily(families, "Smith");
	
	addFamily(families, "Jones"); // error: duplicate family name

	addChild(families, "Jones", "Noah");
	addChild(families, "Jones", "Chris");
	addChild(families, "Smith", "Adam");

	addChild(families, "Jones", "Chris"); // error: dup child name

	addChild(families, "Hawk", "Ethan"); // error: this family is not in
	for (const auto &fam : families)
		for (const auto &child : fam.second)
			cout << fam.first << ", " << child << endl;

	return 0;
}
