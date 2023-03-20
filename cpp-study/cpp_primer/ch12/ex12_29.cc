/*
 * Both are fine. Since this is an infiniet loop, I prefer the original `while` version.
 * */

#include <iostream>
#include "ex12_27_30.h"

void runQueries(std::ifstream &infile)
{
	TextQuery tq(infile);
	do {	
		std::cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(std::cin >> s) || s == "q") break;
		print(std::cout, tq.query(s)) << std::endl;
	} while (true);

}

int main()
{
	std::ifstream file("../data/storyDataFile.txt");
	runQueries(file);
}
