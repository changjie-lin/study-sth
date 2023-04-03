#include <iostream>
#include <string>
#include <vector>

class PrintLine{
public:
	PrintLine(std::istream &i = std::cin) : is(i) { }
	std::string operator()()
	{
		std::string str;
		std::getline(is, str);
		return is ? str : std::string();
	}
private:
	std::istream &is;
};

int main() 
{
	PrintLine pl;
	std::vector<std::string> vec;

	for (std::string tmp; !(tmp = pl()).empty(); ) 
		vec.push_back(tmp);
	for (const auto &s : vec)
		std::cout << s << " ";
	std::cout << std::endl;
}
