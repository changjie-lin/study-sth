#include <iostream>
#include <string>
#include <deque>

using std::string;
using std::deque;
using std::cin;
using std::cout;
using std::endl;

int main() {

	deque<string> deq;
	cout << "Input a sequence of strings:" << endl;
	string str;
	while (cin >> str) deq.push_back(str);

	cout << "Your input are:" << endl;
	for (deque<string>::const_iterator it = deq.cbegin(); it != deq.cend(); ++it)
		cout << *it << endl;
	return 0;
}
