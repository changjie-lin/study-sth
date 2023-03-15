/*
 *  std::map<std::vector<int>::iterator, int> is OK. Because vector<int> support '<' operator.
 *  std::map<std::list<int>::iterator, int> throws error
 *  error: no match for 'operator<' in '__x < __y'
 * */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

int main() {

	
	std::vector<int> iv{1, 2};
	std::list<int> il{3, 4};

	std::map<std::vector<int>::iterator, int> mv{{iv.begin(), 1}};
//	std::map<std::list<int>::iterator, int> ml{{il.begin(), 2}};

	return 0;
}
