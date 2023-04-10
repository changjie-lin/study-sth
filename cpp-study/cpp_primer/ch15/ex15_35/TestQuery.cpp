#include <iostream>
#include "Query.h"
#include "BinaryQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

int main()
{
	Query q = Query("fiery") & Query("bird") | Query("wind");
	std::cout << q << std::endl;

	return 0;
}
