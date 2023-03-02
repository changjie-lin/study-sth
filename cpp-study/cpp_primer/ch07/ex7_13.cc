#include <iostream>
#include "ex7_12_sales_data.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

	Sales_data total(cin);

        if (cin) {

                Sales_data trans(cin);
                while (cin) {
                        if (total.isbn() == trans.isbn()) {
				total.combine(trans);
                        } else {
                        	print(cout, total) << endl;
				total = trans;
			}
			read(cin, trans);
			
                }
		print(cout, total) << endl;
        } else {
                std::cerr << "No data!" << endl;
                return -1;
        }
        return 0;
}
