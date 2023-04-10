#include "QueryResult.h"

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	os << qr.word << " occurs " << qr.nos->size() << " "
	   << (qr.nos->size() > 1 ? "times" : "time") << std::endl;

	for (const auto &ln : *qr.nos)
		os << "\t(line " << ln + 1 << ") " 
	           << *(qr.input->begin() + ln) << std::endl;
	return os;
}

