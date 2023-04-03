#include "ex14_05.h"

int main()
{
	Tree ceiba("001", "ceiba", "1997-07-01");
	Tree maple("002", "maple", "2007-09-01");

	if (ceiba == maple)
		std::cout << "Something is wrong!" << std::endl;
	else
		std::cout << "Good!" << std::endl;

}
