#include <iostream>

void print(const int (&ia)[10])
{
	for (auto elem : ia)
		std::cout << elem << std::endl;
}

int main() {
	int ia[10];
	for (int i = 0; i < 10; i++)
		ia[i] = i;

	print(ia);
}
