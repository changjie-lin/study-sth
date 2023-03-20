#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>

int main()
{
	string filename = "../data/storyDataFile.txt";
	std::ifstream file(filename);
	if (!file.is_open())
		std::cerr << "Fail to open file "<< filename << std::endl;
	
	vector<string> input;
	typedef vector<string>::size_type LineNo;
	std::map<string, std::set<LineNo>> dict;
	LineNo lineNo{0};

	for (string line; std::getline(file, line); ++lineNo) {
		input.push_back(line);
		std::istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear()) {
			std::remove_copy_if(text.begin(), text.end(),
					std::back_inserter(word), ispunct);
			dict[word].insert(lineNo);
		}

	}

	while (true) {
		std::cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(std::cin >> s) || s == "q") break;
		auto found = dict.find(s);
		if (found != dict.end()) {
			std::cout << s << " occurs " << found->second.size()
				  << (found->second.size() > 1 ? " times" : " time")
				  << std::endl;
			for (auto i : found->second)
				std::cout << "\t(line " << i + 1 << ") " << input.at(i)
					  << std::endl;
		} 
		else
			std::cout << s << " occurs 0 times" << std::endl;
	}
}
