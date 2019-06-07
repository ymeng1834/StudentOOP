#ifndef date_hpp
#define date_hpp

#include <iostream>

class Date {
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
public:
	Date(int d, int m, int y);
private:
	int day;
	int month;
	int year;
};

#endif
