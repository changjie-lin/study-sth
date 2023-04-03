#include <stdexcept>

#include "ex14_16_StrBlob.h"
#include "ex14_16_StrBlobPtr.h"
#include "ex14_16_ConstStrBlobPtr.h"

ConstStrBlobPtr::ConstStrBlobPtr() : wptr(), curr(0) {}

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &sb, size_t pos)
    : wptr(sb.data), curr(pos) {}

std::shared_ptr<vector<string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {

        auto ret = wptr.lock();
        if (!ret)
                throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size())
                throw std::out_of_range(msg);
        return ret;
}

const std::string& ConstStrBlobPtr::deref() const
{
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
}

bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
  // compare identity
  return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
  return !(lhs == rhs);
}
