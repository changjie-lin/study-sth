#include <iostream>
#include <vector>

using namespace std;

void sum_adjacent(const vector<int> &v) {
	if (v.size() < 2) return;
/*
	for (decltype(v.size()) i = 0; i < v.size() -1; i++) 
		cout << v[i] + v[i+1] << '\t';
*/
	for (auto it = v.cbegin(); it != v.cend()-1; ++it)
		cout << *it + *(it+1) << '\t';

	cout << endl;
	return;
}

void sum_symmetric(const vector<int> &v) {
/*	auto  mid = (v.size() + 1) / 2;

	for (decltype(mid) i = 0; i != mid; i++) 
		cout << v[i] + v[v.size()-1-i] << '\t';
*/
	for (auto head = v.cbegin(), tail = v.cend()-1; head <= tail; ++head, --tail)
		cout << *head + *tail << '\t';
	cout << endl;
}

int main() {
	
	vector<int> vec;
	int i;
	while (cin >> i) vec.push_back(i);

	cout << "The input integers are:" << endl;
	for (auto j : vec) {
		cout << j << " ";
	}
	cout << endl;

	cout << "The sum of each pair of adjacent elements:" << endl;
	sum_adjacent(vec);

	cout << "The sum of symmetric elements:" << endl;
	sum_symmetric(vec);

	return 0;
}
