/*
 * It will compare the pointers (address of the C-style strings) when calling 
 * equal().
 *
 * For std::string, it will compare the string values.
 *
 * */

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::list;
using std::string;

int main() {

	char s1[] = "Beijing";
	char s2[] = "Shanghai";
	char s3[] = "Shanghai";

	vector<char *> v1{s1, s2};
	vector<char *> v2{s1, s3};
        list<char *> lst1{s1, s2};

	std::cout << "The two vectors are "
		  << (std::equal(v1.begin(), v1.end(), v2.begin()) ? 
		      "equal" : "not equal") << std::endl;	

	std::cout << "The vector and the list are "
		  << (std::equal(v1.begin(), v1.end(), lst1.begin()) ? 
		      "equal" : "not equal") << std::endl;
	
	std::cout << "After explicitly convent to string objects...\n"; 


	string s4(s1), s5(s2), s6(s3);
	vector<string> v3{s4, s5};
	list<string> lst2{s4, s6};
	std::cout << "The vector and the list are "
		  << (std::equal(v3.begin(), v3.end(), lst2.begin()) ? 
		      "equal" : "not equal") << std::endl;
	
	/*
	for (vector<char *>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	*/
	return 0;
}
