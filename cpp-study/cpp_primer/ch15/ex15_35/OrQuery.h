#ifndef ORQUERY_H
#define ORQUERY_H

class TextQuery;
class QueryResult;

#if DEBUG_LEVEL >= 1
#include <iostream>
#endif

#include <string>
#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
	friend Query operator|(const Query &, const Query &);

	OrQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "|") {
#if DEBUG_LEVEL >= 1
    		std::cout << "OrQuery::OrQuery(const Query &, const Query &)" 
			  << std::endl;
#endif
  	}

  	QueryResult eval(const TextQuery &) const override;
};

Query operator|(const Query &, const Query &);

#endif
