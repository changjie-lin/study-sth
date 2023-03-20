#include <iostream>
#include <cstring>
#include <string>

int main() {
	const char *c1 = "Hello";
	const char *c2 = "World";
	unsigned len = std::strlen(c1) + std::strlen(c2) + 1;
	char *c3 = new char[len];

	std::strcpy(c3, c1);
	std::strcat(c3, c2);
	std::cout << c3 << std::endl;
	delete [] c3;

	//std::string s1{"Hello"}, s2{"World"}, s3{s1+s2};
	std::string s1(c1), s2(c2), s3{s1+s2};
	std::cout << s3 << std::endl;

	return 0;
}
