#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;
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

	for (const auto &str : vec) {
		istringstream iss(str);
		string word;
		while (iss >> word)
			cout << word << endl;
	}
        return 0;
}

