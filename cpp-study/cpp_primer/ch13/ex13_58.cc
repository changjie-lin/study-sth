#include <iostream>
#include <vector>
using std::vector;

#include <algorithm>

class Foo {
public:
	Foo() = default;
	Foo(std::initializer_list<int> il) : data(il) { }
	Foo sorted() &&;
	Foo sorted() const &;
	void print() const;
private:
	vector<int> data;
};

Foo Foo::sorted() &&
{	
	std::cout << "Foo::sorted() &&" << std::endl;
	std::sort(data.begin(), data.end());
	return *this;
}
/*
Foo Foo::sorted() const & {
	std::cout << "Foo::sorted() const &" << std::endl;
	Foo ret(*this);
	std::sort(ret.data.begin(), ret.data.end());
	return ret;
}
*/

// exercise 13.56
/*
Foo Foo::sorted() const & {
	Foo ret(*this);
	return ret.sorted();
}
*/

// exercise 13.57
Foo Foo::sorted() const & { return Foo(*this).sorted(); }

void Foo::print() const {
	std::cout << "<" << this << ">" << std::endl;
	for (const auto &i : data)
		std::cout << i << " ";
	std::cout << std::endl;
}


int main()
{
	Foo f1;
	f1.print();
	Foo f2{9, 23, 5, 6, 2, 8};
	f2.print();
	Foo f3 = f2.sorted();
	f2.print();
	f3.print();
	Foo f4 = Foo({ 2, 6, 5, 3, 8, 4, 1, 7 }).sorted(); f4.print();

}
