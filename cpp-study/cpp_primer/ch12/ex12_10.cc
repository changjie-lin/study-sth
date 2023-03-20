#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr) {
	std::cout << "inside the process function: " << ptr.use_count() << "\n";
}

int main() {

	std::shared_ptr<int> p(new int(42));
	std::cout << "Before calling, the count is " << p.use_count() << "\n";
	process(std::shared_ptr<int>(p));

	// show the changes of reference count
	std::cout << "After calling, the count is " << p.use_count() << "\n";

	return 0;
}
