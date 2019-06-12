#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.hpp"

using namespace std;

ostream& operator<< (ostream& os, const Complex& c) {
	os << setprecision(10) << c.real << showpos << c.imag << "i" << noshowpos << endl;
	return os;
}

istream& operator>> (istream& is, Complex& c) {
	is >> c.real >> c.imag;
	return is;
}


bool operator== (const Complex& c1, const Complex& c2) {
	return ((c1.real == c2.real) && (c1.imag == c2.imag));
}

bool operator!= (const Complex& c1, const Complex& c2) {
	return ((c1.real != c2.real) || (c1.imag != c2.imag));
}


Complex::Complex(double real, double imag) : real{real}, imag{imag} {}

Complex::operator bool() const {
	return ((real != 0) || (imag != 0));
}

double Complex::get_real() const {
	return real;
}

double Complex::get_imag() const {
	return imag;
}

Complex& Complex::operator++() {
	++real;
	return (*this);
}

Complex Complex::operator++(int dummy) {
	Complex temp(*this);
	real++;
	return temp;
}

Complex& Complex::operator--() {
	--real;
	return (*this);
}

Complex Complex::operator--(int dummy) {
	Complex temp(*this);
	real--;
	return temp;
}

Complex Complex::operator-=(const Complex& c) {
	real -= c.real;
	imag -= c.imag;
	return (*this);
}

Complex Complex::operator*(const int i) {
	Complex ret(real * i, imag * i);
	return ret;
}


Complex operator+(const Complex& c1, const Complex& c2) {
	Complex ret{c1.get_real() + c2.get_real(), c1.get_imag() + c2.get_imag()};
	return ret;
}

Complex operator-(const Complex& c1, const Complex& c2) {
	Complex ret{c1.get_real() - c2.get_real(), c1.get_imag() - c2.get_imag()};
	return ret;
}





