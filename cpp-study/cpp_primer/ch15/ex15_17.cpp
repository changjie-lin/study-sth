// error: cannot declare variable ‘disc’ to be of abstract type ‘Disc_quote’

#include <iostream>
#include <string>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price) { }
	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n) const
		{ return n * price; }
	
	virtual std::ostream &debug(std::ostream &os) const
	{
		os << "Quote::bookNo " << bookNo
		   << " Quote::price " << price;
		return os;
	}

	virtual ~Quote() = default;
private:
	std::string bookNo;

protected:
	double price = 0.0;
};


class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double price,
		   std::size_t qty, double disc):
		Quote(book, price), quantity(qty), discount(disc) { }
	double net_price(std::size_t) const = 0;
	
	std::ostream &debug(std::ostream &os) const override
	{
		Quote::debug(os) << " Disc_quote::quantity " << quantity
			<< " Disc_quote::discount " << discount;
		return os;
	}
protected:
	std::size_t quantity = 0; // purchase size for the discount to apply
	double discount = 0.0; // fractional discount to apply
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double pri, std::size_t qty, double disc) :
		Disc_quote(book, pri, qty, disc) { }

	double net_price(std::size_t cnt) const override
	{
		if (cnt >= quantity)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
	
};

class Limit_quote : public Disc_quote {
public:
	Limit_quote() = default;
	Limit_quote(const std::string &book, double pri, std::size_t qty, double disc) :
		Disc_quote(book, pri, qty, disc) { }

	double net_price(std::size_t cnt) const override
	{
		if (cnt <= quantity)
			return cnt * (1 - discount) * price;
		else
			return (cnt - quantity) * price + quantity * price * (1 - discount);
	}
	
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
	   << std::endl;
	return ret;
}

int main()
{
	Quote quote("abc", 5.5);
	Bulk_quote bulk("abc", 5.5, 10, 0.2);
	Limit_quote limit("abc", 5.5, 5, 0.2);
	Disc_quote disc("abc", 5.5, 10, 0.2);

	print_total(std::cout, quote, 20);
	print_total(std::cout, bulk, 20);
	print_total(std::cout, limit, 20);

	quote.debug(std::cout) << std::endl;
	bulk.debug(std::cout) << std::endl;
	limit.debug(std::cout) << std::endl;

	return 0;
}
