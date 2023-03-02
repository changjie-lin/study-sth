#include <iostream>

class Debug {
public:
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) { }
	constexpr bool any() { return hw || io || other; }
	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { other = b; }

private:
	bool hw;
	bool io;
	bool other;
};


int main() {
	constexpr Debug io_sub(false, true, false);
	if (io_sub.any())
		std::cout << "Error msg 1" << std::endl;

	const Debug prod(false);
	if (prod.any())
		std::cout << "Prod: no debug" << std::endl;

	Debug dbg(false);
  	if (dbg.any())
    		std::cout << "Error message 3" << std::endl;
  	dbg.set_other(true);
  	if (dbg.any())
    		std::cout << "Error message 4" << std::endl;
	
	return 0;
}
