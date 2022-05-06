#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "complex.h"

using namespace std;

ostream& operator<< (ostream& out, const complexClass& complexNum) {
	string sign = complexNum.im > 0 ? " + " : " - ";
	out << complexNum.re << sign << abs(complexNum.im) << "i\n";
	return out;
}