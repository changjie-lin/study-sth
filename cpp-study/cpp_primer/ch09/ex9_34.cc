#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = v.begin();
    while (iter != v.end()) {
  	if (*iter % 2) {
	    iter = v.insert(iter, *iter);
	    ++iter;
	}
	++iter;
    }

    for (auto i : v) cout << i << " ";

    return 0;
}
