#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>

class StrBlob;

class ConstStrBlobPtr {
	friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);	
	friend bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);	
	friend bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);	
	friend bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);	
	friend bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);	
public:
        ConstStrBlobPtr();
//        ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) :
//                wptr(a.data), curr(sz) {}
//        bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }
	ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0);
	const string& deref() const;
        ConstStrBlobPtr& incr();
private:
        std::shared_ptr<vector<string>> check(std::size_t, const std::string&) const;
        std::weak_ptr<vector<string>> wptr;
        std::size_t curr;

};

bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);	
bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);	
bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);	
bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);	
bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);	
#endif
