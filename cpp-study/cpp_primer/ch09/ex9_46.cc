#include <iostream>
#include <string>

using std::string;
using std::cout;

string decorate(const string &name, const string &prefix, const string &suffix) {
	string result{name}, pre{prefix+ " "}, post{" " + suffix};

	result.insert(0, pre);
	result.insert(result.size(), post);

	return result;
}

int main() {

	string name{"Alonzo Church"};
	name = decorate(name, "Prof.", "Jr.");
	cout << name << std::endl;
	return 0;
}
