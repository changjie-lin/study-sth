class Base {
public:
	void pub_mem();
protected:
	int prot_mem;
private:
	char priv_mem;
};

struct Pub_Derv : public Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }  // legal
};

struct Priv_Derv : private Base {
	int f1() const { return prot_mem; }
	void memfcn(Base &b) { b = *this; }  // legal
};

struct Prot_Derv : protected Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }  // legal
};

struct Derived_from_Public : public Pub_Derv {
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }  // legal
};

struct Derived_from_Private : public Priv_Derv {
	// empty
//	void memfcn(Base &b) { b = *this; }  // illegal
};

struct Derived_from_Protected : public Prot_Derv {
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }  // legal
};

int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;

	Base *p = &d1; // legal
	// illegal. User code may use the derived-to-base conversion only if
	// D inherits publicly from B
	// p = &d2;
	
	// p = &d3;
	
	p = &dd1;

//	p = &dd2;

//	p = &dd3;
}


