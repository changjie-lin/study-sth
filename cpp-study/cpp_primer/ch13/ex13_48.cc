#include <iostream>
#include <vector>
#include "String.h"

void print(const String &s)
{
	std::cout << "<" << &s << "> : <" << s.str() << ">, Size: "
		  << s.size() << ", Capacity: " << s.capacity() << std::endl;
}

void print(std::vector<String> &vs) {
  std::cout << "== vector <" << &vs << "> size:"
            << vs.size() << " capacity: " << vs.capacity() << std::endl;
  for (const auto &s: vs)
    print(s);
}

int main()
{
	std::vector<String> vs;
  	vs.push_back("s1"); print(vs);
  	vs.push_back("s2"); print(vs);
  	vs.push_back("s3"); print(vs);
  	vs.push_back("s4"); print(vs);
  	vs.push_back("s5"); print(vs);
  	vs.push_back("s6"); print(vs);
  	vs.push_back("s7"); print(vs);
  	vs.push_back("s8"); print(vs);

}
