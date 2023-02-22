#include <iostream>
#include <string>

using namespace std;

int main() {

	string s1, s2;
	
	while(cin >> s1 >> s2) {
		auto one = s1.size(), two = s2.size();
		if (one == two)
			cout << "Equal!" << endl;
		else
			cout << "The larger one is: " << ((one > two) ? s1 : s2) << endl;
	}
	return 0;
}
