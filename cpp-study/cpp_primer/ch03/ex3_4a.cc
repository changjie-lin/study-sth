#include <iostream>
#include <string>

using namespace std;

int main() {

	string one, two;
	
	while(cin >> one >> two) {
		if (one == two)
			cout << "Equal!" << endl;
		else
			cout << "The larger one is: " << ((one > two) ? one : two) << endl;
	}
	return 0;
}
