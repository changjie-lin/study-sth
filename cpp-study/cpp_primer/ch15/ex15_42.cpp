/*
 * Exercise 15.42: Design and implement one of the following enhancements:
 *
 *      (a) Print words only once per sentence rather than once per line.
 *      (b) Introduce a history system in which the user can refer to a previous
 *              query by number, possibly adding to it or combining it with another.
 *      (c) Allow the user to limit the results so that only matches in a given
 *              range of lines
 *
 * */

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>

#include "ex15_39.h"

class QueryHistory {
        public:
                Query& operator[](const std::size_t) const;
                void add(const Query &);
                void list() const;
        private:
                std::vector<std::shared_ptr<Query>> history;
};

Query&
QueryHistory::operator[](const std::size_t n) const
{
        if (n > history.size())
                throw std::invalid_argument("invalid input");
        return *(history[n - 1]);
}

void
QueryHistory::add(const Query &q)
{
        auto pq = std::make_shared<Query>(q);
        history.push_back(pq);
}

void
QueryHistory::list() const
{
        if (!history.size()) {
                std::cerr << "Empty history\n";
                return;
        }
        size_t i = 1;
        for (const auto &elem : history) {
                std::cout << i++ << ": " << elem->rep() << '\n';
        }
}

// putback an entire string into stringstream in reverse order
std::stringstream& putback_str(std::stringstream &ss, const std::string &s)
{
        for (auto it = s.crbegin(); it != s.crend(); ++it)
                ss.putback(*it);
        return ss;
}

// build queries using recursion
Query buildQuery(std::stringstream &ss, Query query,
                const QueryHistory &history)
{
        static bool recurseOnce = false;
        std::string op;

        if (!(ss >> op))  // exit condition
                return query;

        if (op == "&") {
                recurseOnce = true;
                query = query & buildQuery(ss, query, history); // give precedence to &
                recurseOnce = false;
                return buildQuery(ss, query, history); // continue with normal recursion
        }

        if (op == "|")
                return query | buildQuery(ss, query, history);

        if (op[0] == '~') {
                putback_str(ss, op.substr(1));
                return ~buildQuery(ss, query, history);
        }

        if (op[0] == '$') // history command prefix
                query = history[stoi(op.substr(1))]; // fetch history
        else
                query = Query(op);

        return (recurseOnce) ? query : buildQuery(ss, query, history);
}


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
	
	//runQueries(infile);
	TextQuery tq(infile);
        std::string input;
        Query query;
        QueryHistory history;
        while (true) {
                if (!std::getline(std::cin, input) || input == "q")
                        break;
                else if (input == "$") { // list history
                        history.list();
                        continue;
                }
                if (!input.empty()) {
                        try {
                                std::stringstream line(input);
                                query = buildQuery(line, query, history);
                                history.add(query);
                                //std::cout << query.eval(tq);
				print(std::cout, query.eval(tq));
                        } catch (std::invalid_argument &err) {
                                std::cerr << err.what() << '\n';
                        }
                }
        }
	
        return 0;
}
