#ifndef NOTQUERY_H
#define NOTQUERY_H

class TextQuery;
class QueryResult;

#if DEBUG_LEVEL >= 1
#include <iostream>
#endif

#include <string>
#include <memory>
#include "Query.h"
#include "Query_base.h"

class NotQuery: public Query_base {
	friend Query operator~(const Query &);
	NotQuery(const Query &query) : q(query)
	{
#if DEBUG_LEVEL >= 1
		std::cout << "NotQuery::NotQuery(const Query &)" << std::endl;
#endif
	}

	QueryResult eval(const TextQuery &) const override;
	std::string rep() const override
	{
#if DEBUG_LEVEL >= 1
    		std::cout << "NotQuery::rep" << std::endl;
#endif
		return "~(" + q.rep() + ")";
	}

	Query q;
};

Query operator~(const Query &);

#endif
