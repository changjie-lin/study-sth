#include <stdexcept>

#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"

StrBlobPtr::StrBlobPtr(StrBlob &sb, size_t pos)
    : wptr(sb.data), curr(pos) {}

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

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr > rhs.curr;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs > rhs);
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs < rhs);
}

StrBlobPtr& StrBlobPtr::operator++()
{
	// if curr already points past the end of the container, can't increment it
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
	// if curr is zero, decrementing it will yield an invalid subscript
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr ret = *this;
	++*this;
	return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}
