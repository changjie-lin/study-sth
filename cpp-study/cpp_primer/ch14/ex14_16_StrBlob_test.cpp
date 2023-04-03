#include "ex14_16_StrBlob.h"
#include "ex14_16_StrBlobPtr.h"
#include "ex14_16_ConstStrBlobPtr.h"

int main()
{
	StrBlob sb1{"Hello", "Hi"}, sb2{"Aloha", "Ciao"};

	if (sb1 == sb2)
		std::cout << "sb1 == sb2" << std::endl;
	
	if (sb1 != sb2)
		std::cout << "sb1 != sb2" << std::endl;


	

}
