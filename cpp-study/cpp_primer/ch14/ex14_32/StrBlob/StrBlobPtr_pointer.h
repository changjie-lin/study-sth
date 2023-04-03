#ifndef STRBLOBPTR_POINTER_H
#define STRBLOBPTR_POINTER_H

class StrBlobPtr;

class StrBlobPtr_pointer {
public:
	StrBlobPtr_pointer() = default;
	StrBlobPtr_pointer(StrBlobPtr* p) : pointer(p) { }

	StrBlobPtr& operator*();
	StrBlobPtr* operator->();

private:
	StrBlobPtr* pointer = nullptr;

};

#endif
