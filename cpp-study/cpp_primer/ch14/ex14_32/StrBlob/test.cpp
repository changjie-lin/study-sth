#include <iostream>

#include "StrBlobPtr_pointer.h"
#include "StrBlobPtr.h"
#include "StrBlob.h"

int main()
{
	StrBlob sb{"ALOHA", "Hello"};
	StrBlobPtr sbp = sb.begin();
	StrBlobPtr_pointer p(&sbp);
	std::cout << p->deref() << std::endl;
	std::cout << (*p).deref() << std::endl;

}
