#include <iostream>
#include "StrVec.h"

void print(const StrVec &sv)
{
	std::cout << "<" << &sv << "> size: " << sv.size()
		  << " capacity: " << sv.capacity() << " contents:";
	for (const auto &s : sv)
		std::cout << s << " ";
	std::cout << std::endl;
}

int main() 
{
	StrVec sv;
	print(sv);

	sv.push_back("Row");
	print(sv);
	sv.push_back("Your");
	print(sv);
	sv.push_back("Boat");
	print(sv);

	{
		StrVec sv2(sv);
		sv2.push_back("Down");
		sv2.push_back("The");
		sv2.push_back("Stream");
		print(sv2);
		//sv = sv2;
		sv = std::move(sv2);
		sv2.push_back("Life");
		print(sv);
		print(sv2);
	}

	sv.reserve(sv.capacity() / 2);
	print(sv);
	sv.reserve(sv.capacity() * 3);
	print(sv);

	sv.resize(sv.size() + 1);
	print(sv);
	sv.resize(sv.size() + 2, "Merrily");
	print(sv);

	StrVec sv3{"Row", "Row", "Row", "Your", "Boat"}; 
	print(sv3);
	StrVec sv4 = {"Gently", "Down", "The", "Stream"};
	print(sv4);
}
