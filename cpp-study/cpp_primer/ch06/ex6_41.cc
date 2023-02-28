#include <iostream>

using std::cout;
using std::endl;

void init(int ht, int wd=80, char bckgrnd = ' ') {
	cout << "ht = " << ht << ", wd = " << wd << ", bckgrnd = " << bckgrnd << endl;
}

int main() {
	
	init(14, 5, '*');

	return 0;
}
