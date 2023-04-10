#ifndef ANDQUERY_H
#define ANDQUERY_H

class TextQuery;
class QueryResult;

#if DEBUG_LEVEL >= 1
#include <iostream>
#endif

#include <string>
#include "BinaryQuery.h"

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query &, const Query &);

  	AndQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "&") 
	{
#if DEBUG_LEVEL >= 1
		std::cout << "AndQuery::AndQuery(const Query &, const Query &)"
                          << std::endl;
#endif
	}

	QueryResult eval(const TextQuery &) const override;
};

Query operator&(const Query &, const Query &);

#endif
