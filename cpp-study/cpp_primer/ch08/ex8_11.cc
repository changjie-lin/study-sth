#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cin;
using std::istringstream;
using std::cout;
using std::endl;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main() {

	string line, word;
	vector<PersonInfo> people;
	istringstream record;

	while (getline(cin, line)) {
		PersonInfo info;
		//istringstream record(line);
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);

		people.push_back(info);
	}

	for (auto &item : people) {
		cout << item.name;
		for (auto &num : item.phones) cout << " " << num;
		cout << endl;
	}
	return 0;
}
