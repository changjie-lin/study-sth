// I prefer the subscript version. It is easier to understand.

#include <iostream>
#include <iterator>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>

using std::ifstream;
using std::map;
using std::string;

int main() {

	//ifstream input("../data/wordcount.txt");
	ifstream input("../data/a_tale_of_two_cities.txt");
	if (!input.is_open()) {
		std::cerr << "Cannot open the file." << std::endl;
		return -1;
	}

	std::istream_iterator<string> in_iter(input), eof;
	std::map<string, std::size_t> word_count;
	string word;
	while (in_iter != eof) {
		word = *in_iter++;
		for (auto &ch : word) ch = tolower(ch);
		
		word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
		//++word_count[word];
		auto ret = word_count.insert({word, 1});
		if (!ret.second)
			++ret.first->second;
	}
	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second
			  << ((w.second > 1) ? " times" : " time") << std::endl;

	return 0;
}
