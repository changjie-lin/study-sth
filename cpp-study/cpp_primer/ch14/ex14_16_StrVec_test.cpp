#include <iostream>

#include "ex14_16_StrVec.h"

int main()
{
	StrVec sv1{"Row", "Row", "Row", "Your", "Boat"},
	       sv2 = sv1,
	       sv3 = {"Gently", "Down", "The", "Stream"};

	std::cout << "sv1 and sv2 is" << ( (sv1 == sv2) ? " " : " not ") 
		  << "equal" << std::endl;

	std::cout << "sv1 and sv3 is" << ( (sv1 == sv3) ? " " : " not ") 
		  << "equal" << std::endl;
}
