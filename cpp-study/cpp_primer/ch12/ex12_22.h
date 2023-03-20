#ifndef CP5_ex12_22_h
#define CP5_ex12_22_h

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using std::vector;
using std::string;

class ConstStrBlobPtr;
class StrBlob{
public:
        using size_type = std::vector<std::string>::size_type;
	friend class ConstStrBlobPtr;

	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

        StrBlob();
        StrBlob(std::initializer_list<string> il);
	StrBlob(StrBlob &sb) : data(sb.data) {}

        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }

        void push_back(const string &t) { data->push_back(t); }
        void pop_back();

        string& front();
        const string& front() const;
        string& back();
        const string& back() const;

private:
        std::shared_ptr<vector<string>> data;
        void check(size_type i, const std::string &msg) const;
};


StrBlob::StrBlob() : data(std::make_shared<vector<string>>()) {}
StrBlob::StrBlob(std::initializer_list<string> il) :
                data(std::make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
        if (i >= data->size())
                throw std::out_of_range(msg);
}

void StrBlob::pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
}

string& StrBlob::front() {
        check(0, "front on empty StrBlob");
        return data->front();
}

const string& StrBlob::front() const {
        check(0, "front on empty StrBlob");
        return data->front();
}

string& StrBlob::back() {
        check(0, "back on empty StrBlob");
        return data->back();
}

const string& StrBlob::back() const {
        check(0, "back on empty StrBlob");
        return data->back();
}


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

ConstStrBlobPtr StrBlob::begin() const
{
        return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
        return ConstStrBlobPtr(*this, data->size());
}

#endif
