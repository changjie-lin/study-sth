#include <iostream>
#include <string>

// Use delegating constructors, add a statement to the body of each of the constructors
// that prints a message whether it is executed.
class Sales_data {
	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, const Sales_data &item);
	friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
public:
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n) { 
		std::cout << "Sales_data(const std::string &s, unsigned n, double p)"
			  << std::endl;
	}
	Sales_data() : Sales_data("", 0, 0.0) {
		std::cout << "Sales_data()" << std::endl;
	}
	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) {
		std::cout << "Sales_data(const std::string &s)" << std::endl;
	}
	Sales_data(std::istream &is) {
		std::cout << "Sales_data(std::istream &is)" << std::endl;
		read(is, *this);
	}

	std::string const& isbn() const { return bookNo; };
    	Sales_data& combine(const Sales_data&);

private:
	double avg_price() const;
    	std::string bookNo;
    	unsigned units_sold = 0;
    	double revenue = 0.0;
};

inline double Sales_data::avg_price() const {
	return units_sold ? revenue / units_sold : 0;
}

// declare nonmember parts of the interface
std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
