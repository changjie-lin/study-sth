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
		ps(new string(s)), i(0) {}
	HasPtr(const char *cs) :
		ps(new string(cs)), i(0) {}
	HasPtr(const HasPtr &hp) :
		ps(new string(*hp.ps)), i(hp.i) {}
/*
	HasPtr& operator=(const HasPtr& hp)
	{	
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
	bool operator<(const HasPtr &rhs) const
	{
		return *ps < *rhs.ps;
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
	std::cout << "-- swap between <" << *lhs.ps << "> and <"
		  << *rhs.ps << ">" << std::endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

int main() 
{
	vector<HasPtr> vec{"C Programming Language", "Thinking in Java",
		"Fluent Python", "Get Programming with Go", "Cpp Primer 5th Edition"};
	
	cout << "Before Sort: " << endl;
	for (const auto &e : vec)
		cout << e.getStr() << endl;

	std::sort(vec.begin(), vec.end());
	cout << "After Sort: " << endl;
	for (const auto &e : vec)
		cout << e.getStr() << endl;
}

