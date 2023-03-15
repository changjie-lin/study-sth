#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {

	std::map<std::string, std::vector<int>> m{{"Beijing", {1, 2, 3, 4, 5}},
	  {"Shanghai", {6, 7, 8,9, 10}}};

	auto it = m.find("Shanghai");

	if (it != m.end()) { 
		std::cout << "Found " << (*it).first << ": ";
		for (auto i : it->second) std::cout << i << " ";
		std::cout << std::endl;
	}
	return 0;
}
