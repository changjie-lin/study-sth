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

	StrVec s5 = {"Life", "is", "but", "a", "dream"};
	for (const auto &e : s5)
		std::cout << e << " ";
	std::cout << std::endl;

	std::cout << "s5[0] " << s5[0] << std::endl;

	const StrVec s6 = s5;
	std::cout << "s6[0] " << s6[0] << std::endl;

}
