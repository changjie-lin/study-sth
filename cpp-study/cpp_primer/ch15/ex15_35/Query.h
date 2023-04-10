#ifndef QUERY_H
#define QUERY_H

#include <memory>
#include <string>
#include <iostream>

class TextQuery;
class QueryResult;
class Query_base;

class Query {
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);

public:
	Query(const std::string &s);
	// interface function: call the corresponding Query_base operations
	QueryResult eval(const TextQuery &t) const;
	std::string rep() const;

private:
	Query(std::shared_ptr<Query_base> query) : pq(query) 
	{
#if DEBUG_LEVEL >=1
		std::cout << "Query::Query(std::shared_ptr<Query_base>)" << std::endl;
#endif
	}
	std::shared_ptr<Query_base> pq;
};

inline std::ostream &operator<<(std::ostream &os, const Query &query)
{
	// Query::rep makes a virtual call through its Query_base pointer to rep()
	return os << query.rep();
}

#endif
