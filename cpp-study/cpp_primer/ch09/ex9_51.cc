#include <iostream>
#include <string>
#include <array>

using std::string;
using std::array;
using std::endl;

class Date {
	friend void print(const Date &date);
public:
	explicit Date(const string &s);
	Date(unsigned y = 1900, unsigned m = 1, unsigned d = 1) :
		year(y), month(m), day(d) {}

private:
	unsigned year;
	unsigned month;
	unsigned day;
	static const array<string, 12> allMonths;
	unsigned parseMonth(const string &str);
};

const array<string, 12> Date::allMonths{"Jan", "Feb", "Mar", "Apr", "May",
    "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void print(const Date &date) {
	std::cout << "Year: "  << date.year << endl
		  << "Month: " << date.month << endl
		  << "Day: "   << date.day << endl; 
}

Date::Date(const string &str) {

	string delimiters{" ,/"};
	auto firstDelimPos = str.find_first_of(delimiters);
	if (firstDelimPos == std::string::npos)
		throw std::invalid_argument("This format is not supported now");
	month = parseMonth(str.substr(0, firstDelimPos));
	auto secondDelimPos = str.find_first_of(delimiters, firstDelimPos + 1);
	auto day_len = secondDelimPos - firstDelimPos - 1;
	day = std::stoi(str.substr(firstDelimPos + 1, day_len));
	year = std::stoi(str.substr(secondDelimPos + 1));

}

unsigned Date::parseMonth(const string &str) {
	
	if (str.empty()) return 0;
	if (std::isdigit(str[0])) return std::stoi(str);

	for (size_t i = 0; i != 12; ++i)
		if (str.find(allMonths[i]) != string::npos) return i + 1;

	return 0;
}

int main()
{
    { //  default case
        auto date = Date();
        print(date);
    }
    { //  case 0: January 1, 1900
        auto date = Date("January 1, 1900");
        print(date);
    }
    { //  case 1: 1/1/1900
        auto date = Date("1/1/1900");
        print(date);
    }
    { //  case 2: Jan 1, 1900
        auto date = Date("Jan 1, 1900");
        print(date);
    }
}


