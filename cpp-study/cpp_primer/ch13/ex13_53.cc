/*
 *  The operations of copy-and-swap
Copy Constructor
-- swap between <Hello> and <World>
Destructor
Move Constructor
-- swap between <World> and <Aloha>
Destructor
 *
 *
 * The operations of two assignments
Copy-assignment operator
Move-assignment operator 
 *
 * */

#include <algorithm>
#include <iostream>
#include <string>
using std::string;

#include <vector>
using std::vector;

using std::cout;
using std::endl;

class HasPtr {
friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const string &s = string()):
		ps(new string(s)), i(0) 
	{
		cout << "Constructor HasPtr(const string)" << endl;
	}
	HasPtr(const char *cs) :
		ps(new string(cs)), i(0) 
	{
		cout << "Constructor HasPtr(const char*)" << endl;
	}
	HasPtr(const HasPtr &hp) :
		ps(new string(*hp.ps)), i(hp.i) 
	{
		cout << "Copy Constructor" << endl;
	}
	HasPtr(HasPtr&& rhs) noexcept : 
		ps(rhs.ps), i(rhs.i)
	{
		rhs.ps = nullptr;
		cout << "Move Constructor" << endl;
	}
/*
	HasPtr& operator=(const HasPtr& hp)
	{
		cout << "Copy-assignment operator" << endl;
		string* new_ps = new string(*hp.ps);
		delete ps;
		ps = new_ps;
		i = hp.i;
		return *this;
	}

	HasPtr& operator=(HasPtr &&rhs) noexcept
	{
		cout << "Move-assignment operator" << endl;
		if (this != &rhs) {
			delete ps;
			ps = rhs.ps;
			i = rhs.i;
			rhs.ps = nullptr;
		}
		return *this;
	}
*/

	HasPtr& operator=(HasPtr rhs)
	{
		swap(*this, rhs);
		return *this;
	}

	bool operator<(const HasPtr &rhs) const
	{
		return *ps < *rhs.ps;
	}
	~HasPtr() 
	{ 
		cout << "Destructor" << endl;
		delete ps; 
	}


	const string& getStr() const { return *ps; }
	void setStr(const string &s) { *ps = s; }
private:
	string *ps;
	int 	i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	std::cout << "-- swap between <" << *lhs.ps << "> and <"
		  << *rhs.ps << ">" << std::endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

int main() 
{
	HasPtr hp1("Hello"), hp2("World"), *ph = new HasPtr("Aloha");
	hp1 = hp2;
	hp1 = std::move(*ph);
	delete ph;
}

