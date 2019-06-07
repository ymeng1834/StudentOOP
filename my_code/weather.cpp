#include <iostream>
#include <string>
#include "date.hpp"
#include "weather.hpp"

using namespace std;

ostream& operator<<(ostream& os, const GPS& gps) {
	os << "latitude: " << gps.latitude << ", longitude: " << gps.longitude;
    return os;
}

/*
Date::Date(int d, int m, int y) {
	if ((d < 1) || (d > 31)) throw(d);
	if ((m < 1) || (m > 12)) throw(m);
	if ((y < 1800) || (y > 2200)) throw(y);
	day = d;
	month = m;
	year = y;
}
ostream& operator<<(ostream& os, const Date& date) {
	os << date.month << "/" << date.day << "/" << date.year;
	return os;
}
*/


WReading:: WReading(Date dt, double temp, double hum, double ws) : date(dt), temperature(temp), humidity(hum), windspeed(ws) {}
ostream& operator<<(ostream& os, const WReading& wr) {
	os << wr.date << " temp: " << wr.temperature << "°; humidity: " << wr.humidity << "; windspeed: " << wr.windspeed << " mph";
	return os;
}


Weather::Weather(string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}
string Weather::get_name() const {
    return station_nm;
}
int Weather:: get_rating() const {
    return rating;
}
void Weather::set_rating(int new_rating) {
    rating = new_rating;
}
void Weather::add_reading(WReading wr) {
	wreadings.push_back(wr);
}
ostream& operator<<(ostream& os, const Weather& w) {
	os << w.get_name() << ":\n\trating: " << w.get_rating() << "\n\t" << w.my_loc;
	for (WReading wr : w.wreadings) {
		cout << "\n\t" << wr;
	}
    return os;
}
