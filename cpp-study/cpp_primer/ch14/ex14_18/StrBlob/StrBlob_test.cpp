#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"

int main()
{
	StrBlob sb1{"Hello", "Hi"}, sb2{"Aloha", "Ciao"};

	if (sb1 < sb2)
		std::cout << "sb1 < sb2" << std::endl;
	
	if (sb1 > sb2)
		std::cout << "sb1 > sb2" << std::endl;

	StrBlobPtr p1(sb1), p2(sb1.end());
	if (p1 < p2)
		std::cout << "p1 < p2" << std::endl;
	
	if (p1 > p2)
		std::cout << "p1 > p2" << std::endl;


	ConstStrBlobPtr p3(sb1), p4(sb1, sb1.size());
	if (p3 < p4)
		std::cout << "p3 < p4" << std::endl;
	
	if (p3 > p4)
		std::cout << "p3 > p4" << std::endl;
	

}
