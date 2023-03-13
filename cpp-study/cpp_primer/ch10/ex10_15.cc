#include <iostream>
#include <algorithm>

int main() {

	int out{33};
	auto f = [out](int in) { return out+in; };

	std::cout << f(4) << std::endl;
	return 0;
}
