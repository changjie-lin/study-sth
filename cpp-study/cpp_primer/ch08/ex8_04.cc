#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

void readFileToVec(const string &filename, vector<string> &vec) {
	ifstream in(filename);
	if (in) {
		string buf;
		while (std::getline(in, buf))
			vec.push_back(buf);
	} else {
		cout << "Fail to open file " << filename << endl;
	}
}

int main() {

	vector<string> vec;
	string filename = "../data/book.txt";
	
	readFileToVec(filename, vec);
	for (const auto &str : vec)
		cout << str << endl;

	return 0;
}
