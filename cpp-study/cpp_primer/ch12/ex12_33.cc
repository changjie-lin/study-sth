#include "ex12_33.h"
#include <sstream>
#include <algorithm>
#include <iterator>

TextQuery::TextQuery(std::ifstream &ifs) : input(new StrBlob)
{
	StrBlob::size_type lineNo{0};
	for (string line; std::getline(ifs, line); ++lineNo) {
		input->push_back(line);
		std::istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear()) {
			std::remove_copy_if(text.begin(), text.end(),
					std::back_inserter(word), ispunct);
			auto &nos = result[word];
			if (!nos)
				nos.reset(new std::set<StrBlob::size_type>);
			nos->insert(lineNo);
		}
	}
}

QueryResult TextQuery::query(const string &str) const
{
	static shared_ptr<std::set<StrBlob::size_type>> nodata(
			new std::set<StrBlob::size_type>);
	auto found = result.find(str);
	if (found == result.end())
		return QueryResult(str, nodata, input);
	else
		return QueryResult(str, found->second, input);
}

std::ostream& print(std::ostream & os, const QueryResult &qr)
{
	os << qr.word << " occurs " << qr.nos->size() << " "
	   << (qr.nos->size() > 1 ? "times" : "time") << std::endl;

	for (auto it = qr.begin(); it != qr.end(); ++it) {
		ConstStrBlobPtr p(*qr.get_file(), *it);
		os << "\t(line " << *it + 1 << p.deref() << std::endl;
	}
/*
	for (auto i : *qr.nos)
//		os << "\t(line " << i + 1 << ") " << qr.input->at(i) << std::endl;
		os << "\t(line " << i + 1 << ") " 
		    << ConstStrBlobPtr(*qr.input, i).deref() << std::endl;
*/
	return os;
}
