#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "../include/Sales_item.h"

int main() {

	std::istream_iterator<Sales_item> in_iter(std::cin), in_eof;
	std::vector<Sales_item> vec;

	while(in_iter != in_eof) vec.push_back(*in_iter++);

	sort(vec.begin(), vec.end(),
	    [](Sales_item const &lhs, Sales_item const &rhs) 
	      { return lhs.isbn() < rhs.isbn(); });

	for (auto bg = vec.cbegin(), ed = bg; bg != vec.cend(); bg = ed) {
		ed = find_if(bg, vec.cend(),
			     [bg](const Sales_item &item) 
		             { return item.isbn() != bg->isbn(); });

		std::cout << std::accumulate(bg, ed, Sales_item(bg->isbn()))
		          << std::endl;

	}

	return 0;
}
