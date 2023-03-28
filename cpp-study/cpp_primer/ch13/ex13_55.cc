#include <iostream>
#include <string>

#include "StrBlob.h"

int main()
{
	StrBlob sb{"Fluent Python"};
	std::cout << sb.back() << std::endl;
	sb.push_back("Cpp Primer 5th Edition");
	std::cout << sb.back() << std::endl;
	std::string s{"Core Java"};
	sb.push_back(s);
	std::cout << sb.back() << std::endl;
}
