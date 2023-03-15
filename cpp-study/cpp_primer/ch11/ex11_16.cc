#include <iostream>
#include <map>
#include <string>

int main() {

	std::map<int, std::string> im;

	int a;
	std::string s;
	while(std::cin >> a >> s) {
		auto it = im.find(a);
		if (it != im.end())
			it->second = s; // assign
		else
			im.insert({a, s});
	}

	for (auto it = im.cbegin(); it != im.cend(); ++it)
		std::cout << it->first << ": " << it->second << std::endl;
	return 0;
}
