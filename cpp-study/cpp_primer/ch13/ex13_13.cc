#include <iostream>
#include <vector>

struct X {
	X() {std::cout << "X()" << std::endl;}
	X(const X&) {std::cout << "X(const X&)" << std::endl;}
	X& operator=(const X&)
	{
		std::cout << "X& operator=(const X&)" << std::endl;
		return *this;
	}
	~X() {std::cout << "~X()" << std::endl;}
};

X f1(X x) {
	std::cout << "X f1(X x)" << std::endl;
	return x;
}

X& f2(X &x) {
	std::cout << "X& f2(X &x)" << std::endl;
	return x;
}

int main() {
//	X x;
//	f1(x);
//	f2(x);
		
//	std::vector<X> vec;
//	vec.push_back(x);

	X* px = new X;
	f2(*px);
	delete px;

	return 0;
}
