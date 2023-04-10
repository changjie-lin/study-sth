#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
	virtual int fcn() { cout << "Base::fcn() " << endl; return 0; }
};

class D1 : public Base {
public:
	// ! fixed
	int fcn() override {
		cout << "D1::fcn() " << endl;
		return 0;
	}
};

class D2 : public D1 {
public:
	int fcn(int) { cout << "D2::fcn(int) " << endl; return 0; }
	int fcn() { cout << "D2::fcn() " << endl; return 0; }
	void f2() { cout << "D2::f2() " << endl; }
};

int main()
{
	Base base;
	D1 d1;
	D2 d2;
	Base *bp1 = &base, *bp2 = &d1, *bp3 = &d2;
	
	bp1->fcn(); // Base::fcn()
	bp2->fcn(); // D1::fcn()
	bp3->fcn(); // D2::fcn()
}
