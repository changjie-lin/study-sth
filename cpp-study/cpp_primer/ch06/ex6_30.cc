#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

bool str_subrange(const string &str1, const string &str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;

	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

	for (decltype(size) i = 0; i != size; ++i) {
		if (str1[i] != str2[i])
			return;
	}
}

int main() {
	string s1{"nihao"}, s2{"nihaoma"};
	if (str_subrange(s1, s2))
		cout << "s1 is substring of s2 (or vice verse)." << endl;

	return 0;
}
