#include "ex12_22.h"
#include <fstream>
#include <iostream>

int main()
{
	std::ifstream ifs("../data/book.txt");
	StrBlob blob;
	for (std::string str; std::getline(ifs, str);)
		blob.push_back(str);

	const StrBlob csb(blob);
	for (ConstStrBlobPtr pbeg(csb.begin()), pend(csb.end());
			pbeg != pend; pbeg.incr())
		std::cout << pbeg.deref() << std::endl;

}
