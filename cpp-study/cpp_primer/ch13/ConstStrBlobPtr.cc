#include "ConstStrBlobPtr.h"

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
