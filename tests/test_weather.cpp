#include <cassert>
#include <iostream>
#include <fstream>
#include "../my_code/date.hpp"
#include "../my_code/weather.hpp"

using namespace std;

/*
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
*/

void make_images1(Image& img1) {
	for (int i = 0; i < 100; i++) {
		Image img2 = Image(10, 10, "foo.txt");
		img2 = img1;
	}
}
void make_images2(Image& img1) {
	for (int i = 0; i < 100; i++) {
		Image img2 = img1;
	}
}


int main() {
	string fnm = "happy.gif!";
	Image img = Image(100, 100, fnm);
	for (int i = 1; i < 1000; i++) {
		make_images1(img);
		make_images2(img);
	}
	exit(0);
	
	
	/*
	Weather irkutsk = Weather("Irkutsk", GPS(46.3, 67.2));
	
	get_wreadings(irkutsk);
	
	cout << irkutsk << endl;
	*/
}
