#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using std::string;

int main() {
	std::multiset<string> c{"a", "b", "b", "a"};
	std::vector<string> v{"x", "y", "z"};

	// 1. legal
	// copy(v.begin(), v.end(), std::inserter(c, c.end()));

	// 2. illegal. multiset has no member function push_back()
	// copy(v.begin(), v.end(), back_inserter(c));
	
	// 3. legal
	// copy(c.begin(), c.end(), inserter(v, v.end()));

	// 4.legal
	copy(c.begin(), c.end(), back_inserter(v));
	

	for (auto i: c) std::cout << i << " ";
	std::cout << std::endl;

	for (auto i : v) std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}
