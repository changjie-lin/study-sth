#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::map;
using std::istringstream;
using std::ifstream;

const string & transform(const string &s, const map<string, string> &m);

map<string, string> buildMap(ifstream &map_file);

void word_transform(ifstream &map_file, ifstream &input) {
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text)) {
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	
	}
}

map<string, string> buildMap(ifstream &map_file) {
	map<string, string> trans_map;
	string key;
	string value;

	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			std::cerr << "no rule for " << key << std::endl;
			//throw std::runtime_error("no rule for " + key);
	return trans_map;
}

const string &
transform(const string &s, const map<string, string> &m) {
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}

int main() {

	string mapFileName("./transform_bad_map.txt");
	string inputFileName("./transform_input_file.txt");

	ifstream map_file(mapFileName), input_file(inputFileName);
	if (!map_file.is_open()) {
		std::cerr << "Fail to open " << mapFileName << '\n';
		return -1;
	}
	if (!input_file.is_open()) {
		std::cerr << "Fail to open " << inputFileName << '\n';
		return -1;
	}

	word_transform(map_file, input_file);
		
	return 0;
}







