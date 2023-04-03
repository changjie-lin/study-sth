#include <iostream>
#include <string>

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
	std::cout << pl() << std::endl;
}
