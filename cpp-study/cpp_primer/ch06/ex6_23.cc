#include <iostream>

using std::cout;
using std::begin;
using std::end;
using std::endl;

void print(const int i) {
	cout << "void print(const int i)" << endl;
	cout << i << endl;
}

void print(const int *beg, const int *end) {
	cout << "void print(const int *beg, const int *end)" << endl;
	while (beg != end)
		cout << *beg++ << endl;
}

void print(const int ia[], size_t size) {
	cout << "void print(const int ia[], size_t size)" << endl;
	for (size_t i = 0; i != size; ++i)
		cout << ia[i] << endl;
}

void print(int (&arr)[2]) {
	cout << "void print(int (&arr)[2])" << endl;
	for (auto elem : arr)
		cout << elem << endl;
}

int main() {
	int i = 0, j[2] = {0, 1};
	print(i);
	print(begin(j), end(j));
	print(j, end(j) - begin(j));
	print(j);

}
