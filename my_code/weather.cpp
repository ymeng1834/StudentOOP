#include <iostream>
#include <string>
#include "date.hpp"
#include "weather.hpp"

using namespace std;

ostream& operator<<(ostream& os, const GPS& gps) {
	os << "latitude: " << gps.latitude << ", longitude: " << gps.longitude;
    return os;
}


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
