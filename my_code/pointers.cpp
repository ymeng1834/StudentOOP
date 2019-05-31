#include <iostream>
#include "pointers.hpp"

using namespace std;

void inc_by_value(int n) {
    ++n;
}


void inc_with_pointer(int* n) {
    ++(*n);
}


void inc_with_reference(int& n) {
    ++n;
}
