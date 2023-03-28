#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>

class StrBlobPtr {
public:
        StrBlobPtr(): curr(0) {}
        StrBlobPtr(StrBlob &a, std::size_t sz = 0) :
                wptr(a.data), curr(sz) {}
        bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
        string& deref() const;
        StrBlobPtr& incr();
private:
        std::shared_ptr<vector<string>> check(std::size_t, const std::string&) const;
        std::weak_ptr<vector<string>> wptr;
        std::size_t curr;

};

#endif
