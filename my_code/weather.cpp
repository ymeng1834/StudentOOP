#include <iostream>
#include <string>
#include "date.hpp"
#include "weather.hpp"

using namespace std;

Image::Image(int w, int h, string flnm)
: width(w), height(h)
{
	filename = flnm;
	image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2) {
	copy_fields(img2);
}

// destructor
Image::~Image() {
	if (image_buf != nullptr) {
		delete [] image_buf;
	}
}

// assignment operator:
Image& Image::operator=(const Image& img2) {
	if (&img2 != this) {
		if (image_buf != nullptr) {
			delete [] image_buf;
		}
		copy_fields(img2);
	}
	return *this;
}

int Image::image_sz() {
	return width * height;
}

void Image::copy_fields(const Image& img2) {
	width = img2.width;
	height = img2.height;
	filename = img2.filename;
	image_buf = new char[image_sz()];
	for (int i = 0; i < image_sz(); i++) {
		image_buf[i] = img2.image_buf[i];
	}
}


/*
 * Setting `display() = 0` here makes this an abstract
 * class that can't be implemented.
 * */
string Image::display(std::string s) {
	return "Displaying image " + s;
}


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
