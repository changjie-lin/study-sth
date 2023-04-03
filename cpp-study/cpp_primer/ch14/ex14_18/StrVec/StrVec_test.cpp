#include <iostream>

#include "StrVec.h"

int main()
{
	StrVec sv1{"Row", "Row", "Row", "Your", "Boat"},
	       sv2 = sv1,
	       sv3 = {"Gently", "Down", "The", "Stream"};

	std::cout << "sv1 and sv2 is" << ( (sv1 == sv2) ? " " : " not ") 
		  << "equal" << std::endl;

	std::cout << "sv1 and sv3 is" << ( (sv1 == sv3) ? " " : " not ") 
		  << "equal" << std::endl;
	
	std::cout <<  ( (sv1 < sv3) ? "sv1 < sv3" : "sv1 > sv3") 
		  << std::endl;

	std::string s{"Merrily"};
	StrVec sv4 = sv1;
	sv4.push_back(s);

	if (sv4 >= sv1)
		std::cout << "sv4 >= sv1" << std::endl;
}
