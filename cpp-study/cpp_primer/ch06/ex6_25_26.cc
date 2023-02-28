#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv) {

	cout << "argc = " << argc << endl;
	string str(argv[1]);
	str += argv[2];
	cout << "The concatenated string is: " << str << endl;
	return 0;
}
