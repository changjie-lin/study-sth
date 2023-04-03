#include "ex14_49.h"

std::istream &operator>>(std::istream &is, Tree& tree)
{
	is >> tree.ID >> tree.species >> tree.plant_date;
	if (!is) tree = Tree();
	return is;
}

std::ostream &operator<<(std::ostream &os, const Tree& tree)
{
	os << tree.ID << " " << tree.species << " " << tree.plant_date;
	return os;
}
bool operator==(const Tree &lhs, const Tree &rhs)
{
	return lhs.ID == rhs.ID;
}
bool operator!=(const Tree &lhs, const Tree &rhs)
{
	return !(lhs == rhs);
}
