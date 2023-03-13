/*
 * "The type of the third argument to accumulate determines which addition
 *  operator is used and is the type that accumulate returns."
 *
 *  Thus all double elements are converted to int.
 * */


#include <iostream>
#include <vector>
#include <numeric>

int main() {

	// Exercise 3
	std::vector<int> v{1, 2, 3, 4};
	std::cout << "ex 3: " << std::accumulate(v.cbegin(), v.cend(), 0)
		  << " (expect: 10)" << std::endl;

	// Exercise 4
	std::vector<double> vd{1.1, 2.2, 3.5, 4.5};
	std::cout << "ex 3: " << std::accumulate(vd.cbegin(), vd.cend(), 0)
		  << " (expect: 11.3)" << std::endl;
	

	return 0;
}
