#include <iostream>

class numbered {
public:
	numbered() : mysn(++sn) {}
	numbered(const numbered&) : mysn(++sn) {}
	int mysn;
private:
	static int sn;
};

int numbered::sn = 0;

void f(const numbered &s) {
	std::cout << s.mysn << std::endl;
}

int main() {

	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}
