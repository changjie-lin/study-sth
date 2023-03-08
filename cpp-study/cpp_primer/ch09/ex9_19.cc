#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;
using std::cin;
using std::cout;
using std::endl;

int main() {

	list<string> lst;
	cout << "Input a sequence of strings:" << endl;
	string str;
	while (cin >> str) lst.push_back(str);

	cout << "Your input are:" << endl;
	for (list<string>::const_iterator it = lst.cbegin(); it != lst.cend(); ++it)
		cout << *it << endl;
	return 0;
}
