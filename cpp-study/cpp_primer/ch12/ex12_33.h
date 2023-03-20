#ifndef CP5_ex12_33_h
#define CP5_ex12_33_h

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
	using ResultIter = std::set<StrBlob::size_type>::iterator;
	QueryResult(const string& s,
		    shared_ptr<std::set<StrBlob::size_type>> p,
		    shared_ptr<StrBlob> f):
		word(s), nos(p), input(f) {}
	ResultIter begin() const { return nos->begin(); }
	ResultIter end() const { return nos->end(); }
	shared_ptr<StrBlob> get_file() const {return input; }
private:
	string word;
	shared_ptr<std::set<StrBlob::size_type>> nos;
	shared_ptr<StrBlob> input;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif
