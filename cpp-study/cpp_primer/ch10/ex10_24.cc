#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;

bool check_size(const string &s, string::size_type sz) {
	return s.size() < sz;
}

int main() {

	std::string str;
	cout << "Input a string: ";
	std::cin >> str;

	std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7};
	auto found = std::find_if(ivec.begin(), ivec.end(),
			std::bind(check_size, str, std::placeholders::_1));

	cout << "Found: " << *found << endl;

	return 0;
}
