#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::fill_n;

int main() {

	// (a)
	cout << "(a)" << endl;

	vector<int> vec;
	list<int> lst;
	int i;
	while (cin >> i) 
		lst.push_back(i);
	copy(lst.cbegin(), lst.cend(), back_inserter(vec));
	
	cout << "The value of vec: \n";
	for (auto i : vec) cout << i << " ";
	cout << endl;

	// (b)
	cout << "\n(b)" << endl;

	vector<int> v2;
	v2.reserve(10);
	fill_n(back_inserter(v2), 10, 0);

	cout << "The value of vec: \n";
	for (auto i : v2) cout << i << " ";
	cout << endl;

	

	return 0;
}
