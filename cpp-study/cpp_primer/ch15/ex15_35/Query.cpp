#include "Query.h"
#include "WordQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query_base.h"

#include <iostream>

Query::Query(const std::string &s) : pq(new WordQuery(s)) 
{
#if DEBUG_LEVEL >= 1
	std::cout << "Query::Query(const std::string &s)" << std::endl;
#endif
}

QueryResult Query::eval(const TextQuery &t) const 
{
#if DEBUG_LEVEL >= 1
	std::cout << "Query::eval()" << std::endl;
#endif
	return pq->eval(t);
}

std::string Query::rep() const
{
#if DEBUG_LEVEL >= 1
	std::cout << "Query::rep()" << std::endl;
#endif
	return pq->rep();
}
