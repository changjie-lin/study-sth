#include <iostream>

#include "String.h"

int main()
{
	String s1 = "Fluent Python",
	       s2{s1},
        	s3 = "Cpp Primer 5th Edition";
	
	std::cout << "s1 and s2 is" << ( (s1 == s2) ? " " : " not ")
                  << "equal" << std::endl;

        std::cout << "s1 and s3 is" << ( (s1 == s3) ? " " : " not ")
                  << "equal" << std::endl;

	std::cout << ( (s1 < s3) ? "s1 < s3" : "s1 > s3" ) << std::endl;

	s2.push_back('!');
	std::cout << ( (s1 <= s2) ? "s1 <= s2" : "s1 > s2" ) << std::endl;
}
