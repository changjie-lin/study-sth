#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>

class ConstStrBlobPtr {
public:
        ConstStrBlobPtr(): curr(0) {}
        ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) :
                wptr(a.data), curr(sz) {}
        bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }
        const string& deref() const;
        ConstStrBlobPtr& incr();
private:
        std::shared_ptr<vector<string>> check(std::size_t, const std::string&) const;
        std::weak_ptr<vector<string>> wptr;
        std::size_t curr;

};

#endif
