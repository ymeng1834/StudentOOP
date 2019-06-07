#include <cassert>
#include <iostream>
#include <fstream>
#include "../my_code/date.hpp"
#include "../my_code/weather.hpp"

using namespace std;

string get_file_name() {
	string filename;
	cout << "Enter file name: ";
	cin >> filename;
	return filename;
}
void get_wreadings(Weather& w) {
	ifstream rfile(get_file_name());
	while (!rfile) {
		cout << "Can't read file. Try again." << endl;
		rfile.open(get_file_name());
	}
	int m, d, y;
	double temp, hum, ws;
	while (rfile >> m >> d >> y >> temp >> hum >> ws) {
		WReading wr = WReading(Date(d, m, y), temp, hum, ws);
		w.add_reading(wr);
	}
	rfile.close();
}


int main() {
	Weather irkutsk = Weather("Irkutsk", GPS(46.3, 67.2));
	
	get_wreadings(irkutsk);
	
	cout << irkutsk << endl;
}
