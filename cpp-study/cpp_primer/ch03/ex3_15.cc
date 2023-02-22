#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	vector<string> v;
	while (cin >> s) v.push_back(s);

	for (auto c:v)
		cout << c << " ";

	cout << endl;
	return 0;
}
