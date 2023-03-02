#include <string>

class Person {
	std::string name;
	std::string address;

public:
	std::string& getName() const { return name; }
	std::string& getAddress() const { return address; }
};

std::istream &read(std::istream &is, Person &p) {
	is >> p.name >> p.address;
	return is;
}

std::ostream &print(std::ostream &os, const Person &p) {
	os << p.getName() << " " << p.getAddress();
	return os;
}
