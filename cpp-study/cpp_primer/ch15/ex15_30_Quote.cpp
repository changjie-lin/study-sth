#include <iostream>
using std::cout;
using std::endl;

#include <string>
#include <vector>
#include <set>
#include <memory>

class Quote {
public:
	Quote()
	{
		cout << "Quote() " << endl;		
	}
	Quote(const std::string &book, double sales_price) :
		price(sales_price), bookNo(book) 
	{ 
		cout << "Quote(const std::string &book, double sales_price)" << endl;
	}
	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n) const
		{ return n * price; }
	
	virtual std::ostream &debug(std::ostream &os) const
	{
		os << "Quote::bookNo " << bookNo
		   << " Quote::price " << price;
		return os;
	}

	virtual ~Quote()
	{
		cout << "~Quote()" << endl;
	}

	Quote(const Quote &rhs) : price(rhs.price), bookNo(rhs.bookNo)
	{
		cout << "Quote(const Quote &rhs)" << endl;
	}

	Quote(Quote &&rhs) noexcept : price(std::move(rhs.price)),
		bookNo(std::move(rhs.bookNo))
	{
		cout << "Quote(Quote &&rhs)" << endl;
	}
	
	Quote &operator=(const Quote &rhs)
	{
		cout << "operator=(const Quote &rhs)" << endl;
		price = rhs.price;
		bookNo = rhs.bookNo;
		return *this;
	}

	Quote &operator=(Quote &&rhs) noexcept
	{
		cout << "operator=(Quote &&rhs)" << endl;
		price = std::move(rhs.price);
		bookNo = std::move(rhs.bookNo);
		return *this;
	}

	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }
protected:
	double price = 0.0;
private:
	std::string bookNo;
};


class Disc_quote : public Quote {
public:
	Disc_quote()
	{
		cout << "Disc_quote()" << endl;
	}
	Disc_quote(const std::string& book, double price,
		   std::size_t qty, double disc):
		Quote(book, price), quantity(qty), discount(disc) 
	{ 
		cout << "Disc_quote(const std::string& book, double price, \
 std::size_t qty, double disc)" << endl;
	}
	double net_price(std::size_t) const = 0;
	
	std::ostream &debug(std::ostream &os) const override
	{
		Quote::debug(os) << " Disc_quote::quantity " << quantity
			<< " Disc_quote::discount " << discount;
		return os;
	}

	~Disc_quote()
	{
		cout << "~Disc_quote()" << endl;
	}

	Disc_quote(const Disc_quote &rhs) : 
		Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) 
	{
    		std::cout << "Disc_quote(const Disc_quote &rhs)" << std::endl;
  	}

	Disc_quote(Disc_quote &&rhs) noexcept:
		Quote(std::move(rhs)), quantity(std::move(rhs.quantity)),
                discount(std::move(rhs.discount)) 
	{
		std::cout << "Disc_quote(Disc_quote &&rhs)" << std::endl;
  	}

	Disc_quote &operator=(const Disc_quote &rhs) 
	{
    		Quote::operator=(rhs);
	    	std::cout << "operator=(const Disc_quote &rhs)" << std::endl;
    		quantity = rhs.quantity;
    		discount = rhs.discount;
    		return *this;
  	}

	Disc_quote &operator=(Disc_quote &&rhs) noexcept
	{
    		Quote::operator=(std::move(rhs));
    		std::cout << "operator=(Disc_quote &&rhs)" << std::endl;
    		quantity = std::move(rhs.quantity);
    		discount = std::move(rhs.discount);
    		return *this;
  	}
protected:
	std::size_t quantity = 0; // purchase size for the discount to apply
	double discount = 0.0; // fractional discount to apply
};

class Bulk_quote : public Disc_quote {
public:
	/*
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double pri, std::size_t qty, double disc) :
		Disc_quote(book, pri, qty, disc) { }
	*/
	using Disc_quote::Disc_quote;
	double net_price(std::size_t cnt) const override
	{
		if (cnt >= quantity)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
	
	Bulk_quote* clone() const & override { return new Bulk_quote(*this); }
	Bulk_quote* clone() && override { return new Bulk_quote(std::move(*this)); }
};

class Limit_quote : public Disc_quote {
public:
	/*
	Limit_quote() = default;
	Limit_quote(const std::string &book, double pri, std::size_t qty, double disc) :
		Disc_quote(book, pri, qty, disc) { }
	*/
	using Disc_quote::Disc_quote;
	double net_price(std::size_t cnt) const override
	{
		if (cnt <= quantity)
			return cnt * (1 - discount) * price;
		else
			return (cnt - quantity) * price + quantity * price * (1 - discount);
	}
	
	Limit_quote* clone() const & override { return new Limit_quote(*this); }
	Limit_quote* clone() && override { return new Limit_quote(std::move(*this)); }
};

class Basket {
public:
	void add_item(const Quote& sale)
	{ items.insert(std::shared_ptr<Quote>(sale.clone())); }

	void add_item(Quote&& sale)
	{
		items.insert(
		  std::shared_ptr<Quote>(std::move(sale).clone()));
	}

	double total_receipt(std::ostream&) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs,
			    const std::shared_ptr<Quote> &rhs)
	{ return lhs->isbn() < rhs->isbn(); }

	std::multiset<std::shared_ptr<Quote>, decltype(compare) *>
		items{compare};

};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
	   << std::endl;
	return ret;
}

double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;
	for (auto iter = items.cbegin();
		  iter != items.cend();
		  iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}



int main()
{

	Basket basket;
	for (auto i = 0; i < 20; ++i) {
		basket.add_item(Quote("abc", 5.5));
		basket.add_item(Bulk_quote("def", 5, 10, 0.2));
		basket.add_item(Bulk_quote("ghi", 5, 10, 0.2));
	}
	basket.total_receipt(std::cout);
	return 0;
}
