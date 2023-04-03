#ifndef EX14_05_H
#define EX14_05_H

#include <iostream>
#include <string>
using std::string;

class Tree {
	friend std::istream &operator>>(std::istream &, Tree&);
	friend std::ostream &operator<<(std::ostream &, const Tree&);
	friend bool operator==(const Tree&, const Tree&);
	friend bool operator!=(const Tree&, const Tree&);
public:
        Tree(string i = "00000") : ID(i) { }  // default constructor
        Tree(string i, string s, string d) : ID(i), species(s), plant_date(d) { }
        Tree(std::istream &is) { is >> *this; }
private:
        string ID, species, plant_date;
};


std::istream &operator>>(std::istream &, Tree&);
std::ostream &operator<<(std::ostream &, const Tree&);
bool operator==(const Tree&, const Tree&);
bool operator!=(const Tree&, const Tree&);
#endif
