#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> vec;
	cout << "Size: " << vec.size()
	     << "\tCapacity: " << vec.capacity() << endl;

	vec.push_back(1);
	cout << "Size: " << vec.size()
             << "\tCapacity: " << vec.capacity() << endl;

	for (auto i = 0; i != 100; ++i) vec.push_back(i);
	cout << "Size: " << vec.size()
             << "\tCapacity: " << vec.capacity() << endl;

	for (auto i = 0; i != 1000; ++i) vec.push_back(i);
	cout << "Size: " << vec.size()
             << "\tCapacity: " << vec.capacity() << endl;

	vec.shrink_to_fit();
	cout << "Size: " << vec.size()
             << "\tCapacity: " << vec.capacity() << endl;

	return 0;
}
