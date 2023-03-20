#include <iostream>
#include <vector>

using std::vector;

vector<int>* make() {

	vector<int> *iv = new vector<int>();
	return iv;
}

void readValues(vector<int> *ptr) {

	std::cout << "Input a sequence of ints: \n";
	int num;
	while (std::cin >> num)
		ptr->push_back(num);
}

void print(vector<int> *iv) {
	std::cout << "The values are: \n";
	for (auto i : *iv) std::cout << i << " ";
	std::cout << std::endl;
}

int main() {

	vector<int> *ptr = make();
	readValues(ptr);
	print(ptr);
	delete ptr;

	return 0;
}
