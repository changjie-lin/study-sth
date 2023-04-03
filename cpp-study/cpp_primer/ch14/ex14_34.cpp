#include <iostream>

class IfThenElse {
public:
	int operator()(bool cond, int y, int n) const
	{
		return cond ? y : n;
	}
};

int main()
{
	int i; 
	IfThenElse tri;
	std::cin >> i;
	std::cout << tri(i, 23, 42) << std::endl;
}
