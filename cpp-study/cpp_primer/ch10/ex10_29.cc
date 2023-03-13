#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>

using std::string;
using std::vector;

int main() {

	std::ifstream ifs("../data/book.txt");
	std::istream_iterator<string> str_it(ifs), eof;

	vector<string> svec(str_it, eof);

	for (auto s : svec) std::cout << s << " ";
	std::cout << std::endl;

	return 0;
}
