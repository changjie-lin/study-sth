#include <iostream>
#include <iterator>
#include <fstream>
#include <map>

using std::ifstream;
using std::map;
using std::string;

int main() {

	ifstream input("../data/a_tale_of_two_cities.txt");
	if (!input.is_open()) {
		std::cerr << "Cannot open the file." << std::endl;
		return -1;
	}

	std::istream_iterator<string> in_iter(input), eof;
	std::map<string, std::size_t> word_count;
	while (in_iter != eof) 
		++word_count[*in_iter++];
	
	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second
			  << ((w.second > 1) ? " times" : " time") << std::endl;

	return 0;
}
