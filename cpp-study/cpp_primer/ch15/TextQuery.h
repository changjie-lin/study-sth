#ifndef TEXT_QUERY_H 
#define TEXT_QUERY_H

#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <map>
#include <set>

#include "StrVec.h"

class QueryResult;
class TextQuery {
public:
	using line_no = std::size_t;
	explicit TextQuery(std::ifstream&);
	QueryResult query(const string&) const;
	
private:
	std::shared_ptr<StrVec> input;
	std::map<std::string, std::shared_ptr<std::set<size_t>>> result;
};

#endif
