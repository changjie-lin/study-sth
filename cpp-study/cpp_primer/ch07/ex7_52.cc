/*
error: could not convert ‘{"978-0590353403", 25, 1.599e+1}’ from ‘<brace-enclosed initializer list>’ to ‘Sales_data’


 * */

#include <string>

// Original
/*
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
*/

struct Sales_data {
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};

int main() {

	Sales_data item = {"978-0590353403", 25, 15.99};
	return 0;
}
