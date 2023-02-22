#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	vector<string> vec;
	string word;

	while (cin >> word) 
		vec.push_back(word);

	for (auto &str : vec)
		for (auto &c : str)
			c = toupper(c);

	for (decltype(vec.size()) i = 0; i != vec.size(); i++) {
		if (i != 0 && i % 8 == 0) 
			cout << endl;
		cout << vec[i] << " ";
	}
	cout << endl;
	return 0;
}
