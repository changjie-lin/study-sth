#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr) {
	std::cout << "inside the process function: " << ptr.use_count() << "\n";
}

int main() {

	auto p = new int();
	auto sp = std::make_shared<int>();

	// (a) legal. Copy by value.
//	process(sp);

	// (b) Illegal. We cannot implicitly convert a built-in pointer to a
	// smart pointer.
//	process(new int());

	// (c) ditto
	//process(p);

	// (d) The compiler doesn't complain. But it is a bad practice.
	// Though we can access p, the behavior is undefined.
	process(std::shared_ptr<int>(p));
	std::cout << *p;

	return 0;
}
