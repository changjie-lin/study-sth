#include <set>
#include "../ch07/ex7_26_sales_data.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() < rhs.isbn();
}

int main() {

	using compareType = bool (*)(const Sales_data &lhs, const Sales_data &rhs);
	std::multiset<Sales_data, compareType> bookstore(compareIsbn);

	return 0;
}
