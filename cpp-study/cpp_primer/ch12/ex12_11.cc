/*
 * core dump error
 * free(): double free detected in tcache 2
 *
 * Because std::shared_ptr<int>(p.get()) constructs a shared_ptr which is
 * independent of `p`. But it shares the same underlying memory with p.
 * Those two pointers have no awareness of each other even though 
 * they point to the same memory.
 *
 * That memory gets freed for the first time when process() ends. Then it gets
 * freed the second time when main() ends. Error occurs.
 * */


#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr) {
	std::cout << "inside the process function: " << ptr.use_count() << "\n";
}

int main() {

	std::shared_ptr<int> p(new int(42));
	std::cout << "Before calling, the count is " << p.use_count() << "\n";
	process(std::shared_ptr<int>(p.get()));

	// show the changes of reference count
	std::cout << "After calling, the count is " << p.use_count() << "\n";

	return 0;
}
