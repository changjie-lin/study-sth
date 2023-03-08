#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

void replaceStr(string &str, const string &oldVal, const string &newVal) {

	for (auto it = str.begin(); it < str.end() - oldVal.size() + 1; ) {
		auto it2 = oldVal.cbegin();
		for(auto it3 = it; it2 != oldVal.cend(); ++it2, ++it3)
			if (*it3 != *it2)
				break;

		if (it2 == oldVal.cend()) {
			string::size_type pos = it - str.begin();
			str.erase(pos, oldVal.size());
			str.insert(pos, newVal);

			it = str.begin() + pos + newVal.size();
		} else
			++it;

	}
}

int main() {

	string str{"tho go thru is difficult. we must go thru tho."};

	replaceStr(str, "tho", "though");
	cout << str << endl;

	replaceStr(str, "thru", "through");
	cout << str << endl;

	return 0;

}
