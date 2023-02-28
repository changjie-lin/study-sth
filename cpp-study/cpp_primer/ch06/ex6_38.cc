#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) &arrRef(int i)
{
	return (i % 2) ? odd : even;
}

int main() {
	int num;
	cout << "Pls input a number: ";
	cin >> num;

	for(auto i : arrRef(num))
		cout << i << " ";
	cout << endl;
	return 0;
}
