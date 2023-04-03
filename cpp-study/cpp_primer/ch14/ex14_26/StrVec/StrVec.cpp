#include <iostream>
#include <utility>
#include "StrVec.h"

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(std::initializer_list<string> il) :StrVec()
{
	for (const string &s : il)
		push_back(s);
}

StrVec &StrVec::operator=(std::initializer_list<std::string> il)
{
	*this = StrVec(il);
	return *this;
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string* e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
	if (elements) {
		for (auto p = first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);

	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::pop_back()
{
	if (size() > 0)
		alloc.destroy(--first_free);
}

void StrVec::reserve(size_t new_cap)
{
	if (new_cap < capacity()) return;

	auto newdata = alloc.allocate(new_cap);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));

	free();
	elements = newdata;
	first_free = dest;
	cap = elements + new_cap;
}

void StrVec::resize(size_t count, const string &s)
{
	if (count > size()) {
		for (size_t i = count - size(); i != 0; --i)
			push_back(s);
	} else if (count < size()) {
		for (size_t i = size() - count; i != 0; --i)
			pop_back();
	}
}

StrVec::StrVec(StrVec &&s) noexcept : 
	elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	std::cout << "StrVec::StrVec(StrVec &&s)" << std::endl;

	s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
	std::cout << "StrVec &StrVec::operator=(StrVec &&rhs)" << std::endl;
	// direcrt test for self-assignment
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		// leave rhs in a destructible state
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
	return lhs.size() == rhs.size() &&
		std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(),
			rhs.begin(), rhs.end());
}

bool operator>(const StrVec &lhs, const StrVec &rhs)
{
	return rhs < lhs;
}

bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs > rhs);
}

bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs < rhs);
}

