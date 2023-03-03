#include <iostream>
#include <fstream>

#include "../ch07/ex7_26_sales_data.h"

int main(int argc, char **argv) {

	std::string filename = argv[1]; // "../data/book.txt"
	std::ifstream input(filename);

	Sales_data total;
	if (read(input, total)) {
        	Sales_data trans;
        	while (read(input, trans)) {
            		if (total.isbn() == trans.isbn())
            			total.combine(trans);
            		else {
                		print(std::cout, total) << std::endl;
                		total = trans;
            		}
        	}
        	print(std::cout, total) << std::endl;
    	} else {
        	std::cerr << "No data?!" << std::endl;
    	}
}
