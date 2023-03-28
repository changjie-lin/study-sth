#include <iostream>
#include <string>

using std::string;

class HasPtr {
public:
	HasPtr(const string &s = string()):
		ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &hp) :
		ps(new string(*hp.ps)), i(hp.i) {}
	const string& getStr() const { return *ps; }
	void setStr(const string &s) { *ps = s; }
private:
	string *ps;
	int 	i;
};

int main() {
	HasPtr hp1("Cpp Primer 5th edition");
	HasPtr hp2 = hp1;
	hp1.setStr("Cpp Primer 6th Edition");

	std::cout << "Original: " << hp1.getStr() << std::endl;
	std::cout << "Copied: " << hp2.getStr() << std::endl;

}
