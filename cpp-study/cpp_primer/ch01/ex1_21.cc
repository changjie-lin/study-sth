#include <iostream>
#include "../include/Sales_item.h"
using namespace std;

int main() {
	Sales_item item1, item2;
	cin >> item1 >> item2;
	if (item1.isbn() == item2.isbn()) {
		cout << item1 + item2 << endl;
	} else {
		cout << "Item 1 isbn: " << item1.isbn() << endl;
		cout << "Item 2 isbn: " << item2.isbn() << endl;
		cerr << "Two items should have the same ISBN." << endl;
	}
	return 0;
}
