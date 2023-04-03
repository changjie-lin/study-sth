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
	
	std::cout << "sb1[0] " << sb1[0] << std::endl;	

	std::cout << "p1[0] " << p1[0] << std::endl;

	std::cout << "--- increment & decrement ----" << std::endl;
	++p1;
	std::cout << "++p1 deref: " << p1.deref() << std::endl;
	--p1;
	std::cout << "--p1 deref: " << p1.deref() << std::endl;

	p1++;
	std::cout << "p1++ deref: " << p1.deref() << std::endl;
	p1--;
	std::cout << "p1-- deref: " << p1.deref() << std::endl;

	StrBlob sb3{"Hello", "Hi", "Aloha", "Ciao"};
	StrBlobPtr p5(sb3);
	p5 += 2;
	std::cout << "p5 += 2, deref: " << p5.deref() << std::endl;
	p5 -= 1;		
	std::cout << "p5 -= 1, deref: " << p5.deref() << std::endl;
	
	StrBlobPtr p6 = p5 - 1;
	std::cout << "p6 deref: " << p6.deref() << std::endl;
	p6 = p6 + 3;
	std::cout << "p6 deref: " << p6.deref() << std::endl;

	std::cout << "p6 - p5 = " << (p6 - p5) << std::endl;

}
