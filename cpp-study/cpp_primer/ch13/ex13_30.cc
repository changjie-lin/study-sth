#include <iostream>
#include <string>

using std::string;

class HasPtr {
friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const string &s = string()):
		ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &hp) :
		ps(new string(*hp.ps)), i(hp.i) {}
/*
	HasPtr& operator=(const HasPtr& hp)
	{	
		std::cout << "HasPtr& operator=(const HasPtr& hp)" << std::endl;
		string* new_ps = new string(*hp.ps);
		delete ps;
		ps = new_ps;
		i = hp.i;
		return *this;
	}
*/
	HasPtr& operator=(HasPtr rhs)
	{
		swap(*this, rhs);
		return *this;
	}
	~HasPtr() { delete ps; }


	const string& getStr() const { return *ps; }
	void setStr(const string &s) { *ps = s; }
private:
	string *ps;
	int 	i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	std::cout << "-- Call swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
	std::cout << "-- swap between <" << *lhs.ps << "> and <"
		  << *rhs.ps << ">" << std::endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

int main() {
	HasPtr hp1("Cpp Primer 5th edition");
	//HasPtr hp2 = hp1;
	HasPtr hp2;
	hp2 = hp1;
	hp1.setStr("Fluent Python");
	swap(hp1, hp2);

	std::cout << "Original: " << hp1.getStr() << std::endl;
	std::cout << "Copied: " << hp2.getStr() << std::endl;

}
