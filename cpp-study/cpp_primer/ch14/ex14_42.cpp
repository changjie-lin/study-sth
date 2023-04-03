#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>

int main()
{
	using std::placeholders::_1;
	std::vector<int> iv{1, 2, 3096, 1024, 1025};
	/*
	size_t count = 0;
	for (auto i : iv)
		if (std::greater<int>()(i, 1024)) ++count;
	*/
	size_t count = std::count_if(iv.cbegin(), iv.cend(),
			std::bind(std::greater<int>(), _1, 1024));
	std::cout << count << " numbers are greater than 1024." << std::endl;

	std::vector<std::string> sv{"pooh", "pooh", "pool"};
	auto found = std::find_if(sv.cbegin(), sv.cend(),
		std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
	std::cout << "The first string that is not equal to \"pooh\" is: "
		  << *found << std::endl;

	std::transform(iv.begin(), iv.end(), iv.begin(),
		std::bind(std::multiplies<int>(), _1, 2));
	for (int i : iv) std::cout << i << " ";
	std::cout << std::endl;
}
