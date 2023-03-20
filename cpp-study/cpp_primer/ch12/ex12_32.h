#ifndef CP5_ex12_32_h
#define CP5_ex12_32_h

#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include <iostream>
#include <fstream>
#include <map>
#include <set>

class QueryResult;
class TextQuery {
public:
	TextQuery(std::ifstream&);
	QueryResult query(const string&) const;
	
private:
	shared_ptr<StrBlob> input;
	std::map<string, shared_ptr<std::set<StrBlob::size_type>>> result;
};


class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(const string& s,
		    shared_ptr<std::set<StrBlob::size_type>> p,
		    shared_ptr<StrBlob> f):
		word(s), nos(p), input(f) {}
private:
	string word;
	shared_ptr<std::set<StrBlob::size_type>> nos;
	shared_ptr<StrBlob> input;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif
