#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>

class StrBlob;

class StrBlobPtr {
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
public:
        StrBlobPtr(): curr(0) {}
	StrBlobPtr(StrBlob& sb, std::size_t pos =0);
	string& deref() const;
        StrBlobPtr& incr();

	string& operator[](size_t n);
	const string& operator[](size_t n) const;

	string& operator*() const;
	string* operator->() const;

	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);

	StrBlobPtr &operator+=(int);
	StrBlobPtr &operator-=(int);
	StrBlobPtr operator+(int) const;
	StrBlobPtr operator-(int) const;
	int operator-(const StrBlobPtr&) const;

private:
        std::shared_ptr<vector<string>> check(std::size_t, const std::string&) const;
        std::weak_ptr<vector<string>> wptr;
        std::size_t curr;

};

bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);

bool operator<(const StrBlobPtr&, const StrBlobPtr&);
bool operator>(const StrBlobPtr&, const StrBlobPtr&);
bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>=(const StrBlobPtr&, const StrBlobPtr&);


inline string& StrBlobPtr::operator[](size_t n)
{
	auto p = check(n, "Out of range");
	return (*p)[n];
}

inline const string& StrBlobPtr::operator[](size_t n) const
{
	auto p = check(n, "Out of range");
	return (*p)[n];
}
#endif
