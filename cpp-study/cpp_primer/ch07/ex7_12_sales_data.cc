#include <iostream>
#include "ex7_12_sales_data.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

	Sales_data s1;
	Sales_data s2("0-201-78345-X");
	Sales_data s3("0-201-78345-X", 5, 2.5);
	Sales_data s4(cin);
	Sales_data s5 = add(s2, s3);

	print(cout, s1) << endl;
	print(cout, s2) << endl;
	print(cout, s3) << endl;
	print(cout, s4) << endl;
	print(cout, s5) << endl;

        return 0;
}
