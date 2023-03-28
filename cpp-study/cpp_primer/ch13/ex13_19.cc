/*
 * No. Becasue every employee is unique in real world.
 *
 * */

#include <iostream>
#include <string>
using std::string;

class Employee {
public:
	Employee();
	Employee(const string&);
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;

	const string name() const { return name_; }
	const int id() const { return id_; }
private:
	string name_;
	int id_;
	static int s_increment;
};

int Employee::s_increment = 0;

Employee::Employee()
{
	id_ = ++s_increment;
}

Employee::Employee(const string &name)
{
	id_ = ++s_increment;
	name_ = name;
}

int main() {
	Employee emp("Ryan Dahl");
	std::cout << "Employee #" << emp.id() << ", Name: " << emp.name() << std::endl;
}

