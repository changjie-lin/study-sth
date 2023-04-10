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

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double pri, std::size_t qty, double disc) :
		Quote(book, pri), min_qty(qty), discount(disc) { }

	double net_price(std::size_t cnt) const override
	{
		if (cnt >= min_qty)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
	
	std::ostream &debug(std::ostream &os) const override
	{
		Quote::debug(os) << " Bulk_quote::min_qty " << min_qty
		   << " Bulk_quote::discount " << discount;
		return os;
	}
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

class Limit_quote : public Quote {
public:
	Limit_quote() = default;
	Limit_quote(const std::string &book, double pri, std::size_t qty, double disc) :
		Quote(book, pri), max_qty(qty), discount(disc) { }

	double net_price(std::size_t cnt) const override
	{
		if (cnt <= max_qty)
			return cnt * (1 - discount) * price;
		else
			return (cnt - max_qty) * price + max_qty * price * (1 - discount);
	}
	
	std::ostream &debug(std::ostream &os) const override
	{
		Quote::debug(os) << " Limit_quote::max_qty " << max_qty
		   << " Limit_quote::discount " << discount;
		return os;
	}
private:
	std::size_t max_qty = 0;
	double discount = 0.0;
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

	print_total(std::cout, quote, 20);
	print_total(std::cout, bulk, 20);
	print_total(std::cout, limit, 20);

	quote.debug(std::cout) << std::endl;
	bulk.debug(std::cout) << std::endl;
	limit.debug(std::cout) << std::endl;

	return 0;
}
