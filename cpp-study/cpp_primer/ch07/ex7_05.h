#include <string>

class Person {
	std::string name;
	std::string address;

public:
	std::string& getName() const { return name; }
	std::string& getAddress() const { return address; }
};

/*
 * Should these functions be const?
 *
 * Yes. Because these functions only mean to read the properties, rather than to modify them.
 * */
