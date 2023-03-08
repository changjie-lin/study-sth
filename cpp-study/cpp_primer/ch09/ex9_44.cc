#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

void replaceStr(string &str, const string &oldVal, const string &newVal) {

	for (string::size_type i = 0; i < str.size(); )
		if (str.substr(i, oldVal.size()) == oldVal) {
			str.replace(i, oldVal.size(), newVal);
			i += newVal.size();
		} else
			++i;
}

int main() {

	string str{"tho go thru is difficult. we must go thru tho."};

	replaceStr(str, "tho", "though");
	cout << str << endl;

	replaceStr(str, "thru", "through");
	cout << str << endl;

	return 0;

}
