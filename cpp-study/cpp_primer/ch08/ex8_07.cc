#include <iostream>
#include <fstream>

#include "../ch07/ex7_26_sales_data.h"

int main(int argc, char **argv) {

	std::string ifile = argv[1]; // "../data/book.txt"
	std::ifstream input(ifile);
	std::string ofile = argv[2]; // "../data/out.txt"
	std::ofstream output(ofile);

	Sales_data total;
	if (read(input, total)) {
        	Sales_data trans;
        	while (read(input, trans)) {
            		if (total.isbn() == trans.isbn())
            			total.combine(trans);
            		else {
                		print(output, total) << std::endl;
                		total = trans;
            		}
        	}
        	print(output, total) << std::endl;
    	} else {
        	std::cerr << "No data?!" << std::endl;
    	}
}
