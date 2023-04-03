#include "ex14_45_sales_data.h"

int main()
{
	Sales_data sd{"Cpp Primer 5th Edition", 3, 128.8};
	std::cout << sd << std::endl;
	std::cout << static_cast<std::string>(sd) << std::endl;
	std::cout << static_cast<double>(sd) << std::endl;

}
