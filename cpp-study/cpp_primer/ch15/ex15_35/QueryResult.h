#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <string>
#include "StrVec.h"


class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
        QueryResult(const string& s,
                    std::shared_ptr<std::set<size_t>> p,
                    std::shared_ptr<StrVec> f):
                word(s), nos(p), input(f) {}

	std::set<size_t>::iterator begin() { return nos->begin(); }
	std::set<size_t>::iterator end() { return nos->end(); }

	std::set<size_t>::const_iterator cbegin() const { return nos->cbegin(); }
	std::set<size_t>::const_iterator cend() const { return nos->cend(); }

	std::shared_ptr<StrVec> get_file() { return input; }

private:
	std::string word;
	std::shared_ptr<std::set<size_t>> nos;
	std::shared_ptr<StrVec> input;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif
