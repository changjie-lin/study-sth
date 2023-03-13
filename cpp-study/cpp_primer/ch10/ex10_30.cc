#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::vector;

int main() {

	std::istream_iterator<int> int_it(std::cin), eof;
	vector<int> iv(int_it, eof);

	std::sort(iv.begin(), iv.end());
	std::ostream_iterator<int> out_iter(std::cout, " ");
	std::copy(iv.begin(), iv.end(), out_iter);

	return 0;
}
