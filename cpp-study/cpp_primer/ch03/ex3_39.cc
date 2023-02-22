#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {

	// use string
	string s1{"Rick"};
	string s2{"Morti"};

	if (s1 == s2)
		cout << "Same string!" << endl;
	else if (s1 > s2)
		cout << "s1 > s2" << endl;
	else
		cout << "s1 < s2" << endl;

	// C-style character string
	const char *str1 = s1.c_str();
	const char *str2 = s2.c_str();
	auto result = strcmp(str1, str2);
	if (result == 0)
		cout << "Same C-string!";
	else if (result < 0) 
		cout << "str1 < str2";
	else
		cout << "str1 > str2";
	cout << endl;
	return 0;
}
