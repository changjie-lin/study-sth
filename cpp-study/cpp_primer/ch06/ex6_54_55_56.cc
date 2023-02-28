#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int func(int, int);
using F = int(int, int);
using PF = int(*)(int, int);

int addNum(int a, int b) {
	return a + b;
}

int subNum(int a, int b) {
	return a - b;
}

int mulNum(int a, int b) {
	return a * b;
}

int divNum(int a, int b) {

	try {
    		if (b == 0)
      		throw std::runtime_error("Divide by 0.");
    		return a / b;
  	} catch (std::runtime_error &err) {
    		std::cerr << err.what() << std::endl;
    		return 0;
 	 }
}


int main() {

	vector<PF> vec{addNum, subNum, mulNum, divNum};
	for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
		cout << (*it)(3, 0) << endl;
	}

	return 0;
}
