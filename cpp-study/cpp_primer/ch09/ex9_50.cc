#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int sum_of_int(const vector<string> &vec) {
	int sum = 0;
	for (auto const &s : vec) sum += std::stoi(s);
	return sum;
}

double sum_of_double(const vector<string> &vec) {
	double sum = 0.0;
	for (auto const &s : vec) sum += std::stod(s);
	return sum;
}

int main() {

	vector<string> vec{"1", "2", "3", "4.5"};
	cout << sum_of_int(vec) << endl;
	cout << sum_of_double(vec) << endl;

	return 0;
}
