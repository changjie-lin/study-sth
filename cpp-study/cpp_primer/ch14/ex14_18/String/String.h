#ifndef STRING_H
#define STRING_H

#include <memory>
#include <initializer_list>
#include <string>

class String {
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
	friend bool operator<(const String&, const String&);
	friend bool operator>(const String&, const String&);
	friend bool operator<=(const String&, const String&);
	friend bool operator>=(const String&, const String&);

public:
	typedef size_t size_type;
	typedef char* iterator;
	typedef const char* const_iterator;
	typedef char& reference;
	typedef const char& const_reference;

	String() : first_elem(nullptr), first_free(nullptr), cap(nullptr) { }
	String(const_iterator);
	String(std::initializer_list<char>);

	String(const String&);
	String &operator=(const String&);
	String &operator=(const_iterator);

	String(String&&) noexcept;
	String &operator=(String&&) noexcept;

	~String();

	void push_back(const_reference);
	void pop_back();

	void reserve(size_type);
	void resize(size_type, const_reference = char());

	bool empty() const { return first_elem == first_free; }
	size_type size() const { return first_free - first_elem; }
	size_type capacity() const { return cap - first_elem; }

	iterator begin() { return first_elem; }
	iterator end() { return first_free; }
	iterator begin() const { return first_elem; }
	iterator end()  const { return first_free; }
	iterator cbegin() const { return first_elem; }
	iterator cend()  const { return first_free; }

	std::string str() const;
private:
	static std::allocator<char> alloc;

	iterator first_elem;
	iterator first_free;
	iterator cap;
	// These three pointers should be either all nullptr or all pointing to 
	// the same memory block.
	
	void reallocate(size_type);
	void free();
};

bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);
bool operator<(const String&, const String&);
bool operator>(const String&, const String&);
bool operator<=(const String&, const String&);
bool operator>=(const String&, const String&);

#endif
