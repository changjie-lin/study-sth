#ifndef STRVEC_H
#define STRVEC_H

#include <string>
using std::string;

#include <memory>  // allocator, uninitialized_copy
#include <initializer_list>


class StrVec {
	friend bool operator==(const StrVec&, const StrVec&);
	friend bool operator!=(const StrVec&, const StrVec&);
	friend bool operator>(const StrVec&, const StrVec&);
	friend bool operator<(const StrVec&, const StrVec&);
	friend bool operator>=(const StrVec&, const StrVec&);
	friend bool operator<=(const StrVec&, const StrVec&);
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(std::initializer_list<string>);
	
	StrVec(const StrVec&);
	StrVec &operator=(const StrVec&);

	StrVec(StrVec&&) noexcept;
	StrVec &operator=(StrVec&&) noexcept;
	
	~StrVec();

	void push_back(const string&);

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }

	void pop_back();
	void reserve(size_t);
	void resize(size_t, const string& = string());

private:
	static std::allocator<string> alloc;
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	std::pair<string*, string*>
		alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();

	string *elements;
	string *first_free;
	string *cap;
};

bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);

bool operator>(const StrVec&, const StrVec&);
bool operator<(const StrVec&, const StrVec&);
bool operator>=(const StrVec&, const StrVec&);
bool operator<=(const StrVec&, const StrVec&);
#endif
