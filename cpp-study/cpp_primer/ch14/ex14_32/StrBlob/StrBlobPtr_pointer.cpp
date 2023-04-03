#include "StrBlobPtr_pointer.h"
#include "StrBlobPtr.h"

StrBlobPtr& StrBlobPtr_pointer::operator*()
{
	return *(this->pointer);
}

StrBlobPtr* StrBlobPtr_pointer::operator->()
{
	return & this->operator*();
}
