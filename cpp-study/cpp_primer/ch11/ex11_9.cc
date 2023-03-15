#include <iostream>
#include <string>
#include <list>
#include <map>

int main() {

	std::map<std::string, std::list<int>> words{
		{"it", {0, 1}}, {"pat", {3, 4}}, {"tai", {2, 5, 6}}};

	for (const auto &w : words){
		std::cout << w.first << ":";
		for (const auto &n : w.second)
			std::cout << " " << n;
		std::cout << std::endl;
	}
	return 0;
}
