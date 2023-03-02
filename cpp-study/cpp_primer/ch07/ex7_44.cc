//  error: no matching function for call to ‘NoDefault::NoDefault()’

#include <vector>

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

	std::vector<NoDefault> vec(10);
	return 0;
}
