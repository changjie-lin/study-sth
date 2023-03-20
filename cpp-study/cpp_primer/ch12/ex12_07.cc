#include <iostream>
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

shared_ptr<vector<int>> make() {
	return std::make_shared<vector<int>>();
}

/*
vector<int>* make() {

	vector<int> *iv = new vector<int>();
	return iv;
}
*/
void readValues(shared_ptr<vector<int>> ptr) {

	std::cout << "Input a sequence of ints: \n";
	int num;
	while (std::cin >> num)
		ptr->push_back(num);
}

void print(shared_ptr<vector<int>> p) {
	std::cout << "The values are: \n";
	for (auto i : *p) std::cout << i << " ";
	std::cout << std::endl;
}

int main() {

	shared_ptr<vector<int>> ptr = make();
	readValues(ptr);
	print(ptr);
	//delete ptr;

	return 0;
}
