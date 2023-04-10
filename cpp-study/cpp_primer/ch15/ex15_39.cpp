/*
 * Exercise 15.39: Implement the Query and Query_base classes. Test your
 * application by evaluating and printing a query such as the one in Figure
 * 15.3 (p. 638).
 *
 * */

#include <iostream>
#include <string>

#include "ex15_39.h"

void runQueries(std::ifstream &infile)
{
        TextQuery tq(infile);
	Query q = Query("fiery") & Query("bird") | Query("wind");
	std::cout << "==================" << std::endl;
	std::cout << q << std::endl;
	std::cout << "==================" << std::endl;
	print(std::cout, q.eval(tq)) << std::endl;

        while (true) {
                std::cout << "enter word to look for, or q to quit: ";
                string s;
                if (!(std::cin >> s) || s == "q") break;
                print(std::cout, tq.query(s)) << std::endl;
        }
}


int main()
{
	std::string filename{"../data/storyDataFile.txt"};
	std::ifstream infile(filename);
	if (!infile.is_open()) {
		std::cerr << "Fail to open file: " << std::endl;
		return -1;
	}
	
	runQueries(infile);
        return 0;
}
