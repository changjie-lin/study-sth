#include <iostream>
#include <list>
#include <deque>

using std::list;
using std::deque;
using std::cout;
using std::cin;
using std::endl;

int main() {
	cout << "Input a sequence of int values:" << endl;
	int num;
	list<int> lst;
	while (cin >> num) lst.push_back(num);

	deque<int> odds, evens;
	for (auto &i : lst) {
		if (i % 2 == 0)
			evens.push_back(i);
		else
			odds.push_back(i);
	}

	cout << "The odd numbers:";
	for (auto &i : odds) cout << i << " ";
	cout << endl;

	cout << "The even numbers:";
	for (auto &i : evens) cout << i << " ";
	cout << endl;

	return 0;
}
