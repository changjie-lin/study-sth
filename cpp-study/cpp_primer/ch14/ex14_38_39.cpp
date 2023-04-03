#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

class InRange {
public:
	InRange(std::size_t u = 10, std::size_t d = 1) : up(u), down(d) { }
	bool operator()(const std::string &s)
	{
		return s.length() >= down && s.length() <= up;
	}
private:
	std::size_t up;
	std::size_t down;
};

int main()
{
	std::string filename{"../data/storyDataFile.txt"};
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		std::cerr << "Fail to open file: " << filename;
		return -1;
	}

	InRange ex38{InRange()}, ex39{InRange(5, 1)};
	std::size_t ans38{0}, ans39 = 0;

	for (std::string word; ifs >> word; ) {
		if (ex38(word)) ++ans38;
		if (ex39(word)) ++ans39;
	}
	std::cout << "There are " << ans38 << " words in range [1, 10]" << std::endl;
	std::cout << "There are " << ans39 << " words in range [1, 5]" << std::endl;
}
