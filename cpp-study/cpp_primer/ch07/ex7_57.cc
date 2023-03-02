#include <iostream>
#include <string>

class Account {
	friend std::ostream &print(std::ostream &os, const Account &item);
public:
	Account(const std::string &ow, double am) :
		owner(ow), amount(am) {}
	Account() : Account("", 0.0) {}
	Account(const std::string &ow) : Account(ow, 0.0) {}
	void calculate() {  amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
	
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
	static constexpr int period = 30;
	double daily_tbl[period];
};

double Account::interestRate = initRate();

double Account::initRate() {
	return 0.1;
}

void Account::rate(double r) {
	interestRate = r;
}

std::ostream &print(std::ostream &os, const Account &item) {
	os << item.owner << " " << item.amount;
	return os;
}

int main() {
	Account a1;
	Account a2("CJ");
	Account a3("SZ", 100);

	print(std::cout, a1) << std::endl;
	print(std::cout, a2) << std::endl;
	print(std::cout, a3) << std::endl;
}
