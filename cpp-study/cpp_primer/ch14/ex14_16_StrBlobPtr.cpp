#include <stdexcept>

#include "ex14_16_StrBlob.h"
#include "ex14_16_StrBlobPtr.h"
#include "ex14_16_ConstStrBlobPtr.h"

StrBlobPtr::StrBlobPtr(StrBlob &sb, size_t pos)
    : wptr(sb.data), curr(pos) {}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

std::shared_ptr<vector<string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {

        auto ret = wptr.lock();
        if (!ret)
                throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size())
                throw std::out_of_range(msg);
        return ret;
}

std::string& StrBlobPtr::deref() const
{
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
}
