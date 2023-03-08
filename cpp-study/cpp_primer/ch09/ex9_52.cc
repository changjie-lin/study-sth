#include <stack>
#include <iostream>
#include <string>

using std::stack;
using std::string;
using std::cout;
using std::endl;

int main() {

	auto &expr = "This is (Spring(awesome)((((wooooooooo))))) and (covid) is over";
	auto repl = '#';
	auto seen = 0;

	stack<char> stck;

	for (auto c : expr) {

		stck.push(c);
		if (c == '(') ++seen;
		if (seen && c == ')') {// pop elements down to the open parenthesis
			while (stck.top() != '(') stck.pop();

			stck.pop();
			stck.push(repl);
			--seen;
		}
	}


	string output;
	for (; !stck.empty(); stck.pop()) output.insert(output.begin(), stck.top());

	cout << output << endl;

	return 0;
}
