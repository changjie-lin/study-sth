#include <iostream>
#include "ex7_06_sales_data.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

	Sales_data total;

        if (read(cin, total)) {
                Sales_data trans;
                while (read(cin, trans)) {
                        if (total.isbn() == trans.isbn()) {
				total.combine(trans);
                        } else {
                        	print(cout, total) << endl;
				total = trans;
			}
                }
		print(cout, total) << endl;
        } else {
                std::cerr << "No data!" << endl;
                return -1;
        }
        return 0;
}
