#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cin;
using std::istringstream;
using std::ostringstream;
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;

struct PersonInfo {
	string name;
	vector<string> phones;
};

bool valid(const string& str) {
	for (auto &i : str) 
		if ( !isdigit(i) )
			return false;
	return true;
}

string format(const string &str) {
	return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main() {

	string line, word;
	vector<PersonInfo> people;
	string filename = "../data/phonebook.txt";
	ifstream in(filename);

	if (in) {
		while (std::getline(in, line)) {
			PersonInfo info;
			istringstream record(line);
			record >> info.name;
			while (record >> word) info.phones.push_back(word);

			people.push_back(info);
		}
		
	} else {
		cout << "Fail to open file " << filename << endl;
		return -1;
	}

	for (const auto &entry : people) {
		ostringstream formatted, badNums;
		for (const auto &nums: entry.phones) {
			if (!valid(nums)) {
				badNums << " " << nums;
			} else
				formatted << " " << format(nums);
		}
		if (badNums.str().empty())
			cout << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error: " << entry.name 
			     << " invalid number(s) " << badNums.str() << endl;
	}

	return 0;
}
