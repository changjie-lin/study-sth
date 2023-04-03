#include <iostream>
#include <vector>
#include <algorithm>

class IsEqual {
public:
	IsEqual(int v) : num(v) { }
	bool operator()(int val) { return val == num; }
private:
	int num;
};

int main()
{
	std::vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8};
	std::replace_if(iv.begin(), iv.end(), IsEqual(8), 0);

	for (auto i : iv)
		std::cout << i << " ";
	std::cout << std::endl;
}
