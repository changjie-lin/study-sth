#include <iostream>
#include <memory>
#include <string>

int main() {

	std::allocator<std::string> alloc;
	const size_t n = 10;
	auto const p = alloc.allocate(n);

	std::string s;
	std::string *q = p;
	while(std::cin >> s && q != p + n)
		alloc.construct(q++, s);

	const size_t size = q - p;
	for (auto pos = p; pos != q; ++pos)
		std::cout << *pos << " ";
	std::cout << std::endl;

	// free
	while(q != p)
		alloc.destroy(--q);
	alloc.deallocate(p, n);


	return 0;
}
