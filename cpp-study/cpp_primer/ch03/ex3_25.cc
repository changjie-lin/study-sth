#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<unsigned> scores(11, 0);
	unsigned grade;
	auto b = scores.begin(), e = scores.end();
	while (cin >> grade) {
		if (grade <= 100 && ( (b + grade/10) < e )) {
			// ++scores[grade/10];
			++(*(b + grade/10));
		}
	}

	for (auto value : scores)
		cout << value << " ";

	cout << endl;
	return 0;
}
