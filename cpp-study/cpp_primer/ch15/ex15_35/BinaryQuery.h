#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#if DEBUG_LEVEL >= 1
#include <iostream>
#endif

#include <string>
#include "Query_base.h"
#include "Query.h"

class BinaryQuery: public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) :
		lhs(l), rhs(r), opSym(s)
	{
#if DEBUG_LEVEL >= 1
		std::cout << "BinaryQuery::BinaryQuery(const Query &, const Query &, "
                 "const std::string &)" << std::endl;
#endif
	}

	std::string rep() const override 
	{
#if DEBUG_LEVEL >= 1
		std::cout << "BinaryQuery::rep" << std::endl;
#endif
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}

	Query lhs, rhs;
	std::string opSym;
};

#endif
