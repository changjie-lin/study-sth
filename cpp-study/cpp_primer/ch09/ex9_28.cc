#include <iostream>
#include <forward_list>
#include <string>

using std::forward_list;
using std::cout;
using std::endl;
using std::string;

void insertStr(forward_list<string> &lst, const string &s1, const string &s2) {
	
	auto prev = lst.before_begin();
	for (auto curr = lst.begin();
	     curr != lst.end(); prev=curr++) {

		if (*curr == s1) { 
			curr = lst.insert_after(curr, s2);
			return;
		}
	}
	lst.insert_after(prev, s2);
}

int main() {
	
	forward_list<string> flst{string("nihao"), string("Aloha"), string("Hello")};

	insertStr(flst, string("hi"), string("haha"));
	for (auto &s : flst) cout << s << " ";
	cout << endl;
	return 0;
}
