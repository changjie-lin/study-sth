#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {

	vector<char> vec{'a', 'b', 'c'};
	string str(vec.begin(), vec.end());

	cout << str << endl;
	return 0;
}
