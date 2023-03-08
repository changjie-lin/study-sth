#include <iostream>
#include <string>
#include <vector>
#include <list>

int main() {

	std::list<char *> lst{"Hello", "ALOHA", "ni hao"};
	std::vector<std::string> vec;

	vec.assign(lst.cbegin(), lst.cend());
	for (const auto &str : vec) std::cout << str << std::endl;
	return 0;
}
