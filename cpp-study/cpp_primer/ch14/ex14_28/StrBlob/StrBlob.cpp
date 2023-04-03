#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"

StrBlob::StrBlob() : data(std::make_shared<vector<string>>()) {}

StrBlob::StrBlob(std::initializer_list<string> il) :
        data(std::make_shared<vector<string>>(il)) {}

StrBlob::StrBlob(const StrBlob &sb) :
	data(std::make_shared<vector<string>>(*sb.data)) {}

StrBlob& StrBlob::operator=(const StrBlob &sb) {
	data = std::make_shared<vector<string>>(*sb.data);
	return *this;
}

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

StrBlobPtr StrBlob::begin() {
  return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
  return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::begin() const {
  return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const {
  return ConstStrBlobPtr(*this, data->size());
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data == *rhs.data;	
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);	
}


bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	return std::lexicographical_compare(lhs.data->begin(),
			lhs.data->end(),
			rhs.data->begin(),
			rhs.data->end());
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
	return rhs < lhs;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs > rhs);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs < rhs);
}


