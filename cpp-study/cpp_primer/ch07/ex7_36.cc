/*
The output of the original program:

> x(3, 5), rem = 0, base = 3

Best practice:
It is a good idea to write constructor initializers in the same order as the members are declared. Moreover, when possible, avoid using members to initialize other members.

 * */

#include <iostream>

/*struct X {
	X (int i, int j) : base(i), rem(base % j) { } 
	int rem, base;
};
*/
struct X {
	X (int i, int j) : rem(i % j), base(i) { } 
	int rem, base;
};

int main() {
	X x(3, 5);
	std::cout << "x(3, 5), rem = " << x.rem << ", base = " << x.base << "\n";	
	return 0;
}
