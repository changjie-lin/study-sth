#include <iostream>
#include <map>
#include <vector>
#include <string>

int main() {

	// 11.24
	// m is searched fo the the element whose key is 0. The element is not found
	// 
	// A new key-value pair is inserted into m. The key is an int holding 0. The
	// value is initialized, meaning in this case that the value is 0.
	//
	// The newly inserted element is fetched and is given the value 1.
	std::map<int, int> m;
	m[0] = 1;

	for (const auto e: m) std::cout << e.first << ": " << e.second << std::endl;

	// 11.25
	// segmentation fault
	//
	// It tries to access the value at position 0. There is no such element in
	// this vector. The out-of-range error occurs.
	std::vector<int> v;
//	v[0] = 1;

	for (const auto e: v) std::cout << e << std::endl;

	// 11.26
	std::map<int, std::string> im{{1, "Beijing"}, {2, "Shanghai"}};
	
	std::map<int, std::string>::key_type subscriptOne = 1;
	int subscriptTwo = 2; // euqivalent
	
	std::map<int, std::string>::mapped_type retOne = im[subscriptOne];
	std::string retTwo = im[subscriptTwo];

	std::cout << subscriptOne << ": " << retOne << "\n"
		  << subscriptTwo << ": " << retTwo << std::endl;

	return 0;
}
