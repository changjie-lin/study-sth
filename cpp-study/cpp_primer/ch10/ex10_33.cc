#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>


int main(int argc, char **argv) {

	if (argc != 4) {
		std::cout << "Usage: ./a.out ex10_33.in odd.out even.out";
		return -1;
	}

	std::ifstream ifs(argv[1]);
	std::ofstream ofs_odd(argv[2]), ofs_even(argv[3]);

	std::istream_iterator<int> in_iter(ifs), in_eof;
	std::ostream_iterator<int> out_iter_odd(ofs_odd, " "), 
		                   out_iter_even(ofs_even, "\n");

	std::for_each(in_iter, in_eof,
		      [&](const int i) {
			  if ( i % 2 )
			  	//*out_iter_odd++ = i;
			  	out_iter_odd = i;
			  else
			  	//*out_iter_even++ = i;
			  	out_iter_even = i;
		      });

	return 0;
}
