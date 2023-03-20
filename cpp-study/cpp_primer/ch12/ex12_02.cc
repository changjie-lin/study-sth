#include <iostream>

#include "ex12_02.h"

int main() {

	StrBlob sb{"Parsley", "Sage", "Rosemary", "Thyme"};
	const StrBlob csb{"Apple", "Banana", "Orange"};

	std::cout << csb.front() << " " << csb.back() << std::endl;
	sb.back() = "lemon";
	std::cout << sb.front() << " " << sb.back() << std::endl;

	return 0;
}
