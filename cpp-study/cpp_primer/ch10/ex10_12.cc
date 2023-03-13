#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

#include "../ch07/ex7_26_sales_data.h"

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) {

	return sd1.isbn() < sd2.isbn();
}

int main(int argc, char **argv) {

	if (argc < 2) {
		std::cerr << "Usage: ./a.out ex10_12.in" << std::endl;
		return -1;
	}

	std::ifstream in(argv[1]);
	if (!in) {
		std::cerr << "Fail to open input file: " << argv[1] << std::endl;
		return -2;
	}

	std::vector<Sales_data> vec;
	for (Sales_data sd; read(in, sd); vec.push_back(sd)) { } // empty

	std::cout << "Before sort: \n";
	for (const auto &sd : vec)
		print(std::cout, sd) << std::endl;

	std::cout << "\nAfter sort: \n";
	std::sort(vec.begin(), vec.end(), compareIsbn);

	for (const auto &sd : vec)
		print(std::cout, sd) << std::endl;

	return 0;
}
