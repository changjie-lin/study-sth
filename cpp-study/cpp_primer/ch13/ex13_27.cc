#include <iostream>
#include <string>

using std::string;

class HasPtr {
public:
	HasPtr(const string &s = string()):
		ps(new string(s)), i(0), use(new std::size_t(1)) {}
	
	HasPtr(const HasPtr &p) : 
		ps(p.ps), i(p.i), use(p.use) { ++*use; }
	HasPtr& operator=(const HasPtr &rhs)
	{
		++*rhs.use;
		if (--*use == 0) {
			delete ps;
			delete use;
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		return *this;
	}
	~HasPtr() 
	{
		if (--*use == 0) {
			delete ps;
			delete use;
		}
	}

	/*
	HasPtr(const HasPtr &hp) :
		ps(new string(*hp.ps)), i(hp.i) {}
	HasPtr& operator=(const HasPtr& hp)
	{
		string* new_ps = new string(*hp.ps);
		delete ps;
		ps = new_ps;
		i = hp.i;
		return *this;
	}
	~HasPtr() { delete ps; }
	*/

	const string& getStr() const { return *ps; }
	void setStr(const string &s) { *ps = s; }
private:
	string *ps;
	int 	i;
	std::size_t *use;
};

int main() {
	HasPtr hp1("Cpp Primer 5th edition");
	HasPtr hp2 = hp1;
	hp1.setStr("Cpp Primer 6th Edition");

	std::cout << "Original: " << hp1.getStr() << std::endl;
	std::cout << "Copied: " << hp2.getStr() << std::endl;

}
