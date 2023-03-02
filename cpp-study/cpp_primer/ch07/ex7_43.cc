class NoDefault {
public:
	NoDefault(int i) : num(i) { }
private:
	int num;
};

class C {
public:
	C() : nd(0) { }
private:
	NoDefault nd;
};

int main() {

	C c;
	return 0;
}
