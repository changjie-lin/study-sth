#include <iostream>
#include <vector>
#include <list>

int main() {

	std::list<int> ilst{1, 2, 3};
	std::vector<int> ivec{4, 5, 6};

	// from list<int> to vector<double>
	std::vector<double> dvec1(ilst.begin(), ilst.end());
	for (auto i : dvec1) std::cout << i << " ";
	std::cout << std::endl;

	// from vector<int> to vector<double>
	std::vector<double> dvec2(ivec.begin(), ivec.end());
	for (auto i : dvec2) std::cout << i << " ";
	std::cout << std::endl;
	
	return 0;
}
