#ifndef complex
#define complex

#include <iostream>
#include <cstdlib>

using namespace std;

class complexClass {
	double re;
	double im;
public:
	complexClass(double re = 0, double im = 0) {
		this->re = re;
		this->im = im;
	}

	void setterRe(double re) { this->re = re; }
	void setterIm(double im) { this->im = im; }

	double moduleFoo() { return sqrt(pow(re, 2) + pow(im, 2)); }

	complexClass operator + (const complexClass& other) {
		complexClass bufferNum(this->re + other.re, this->im + other.im);
		return bufferNum;
	}
	complexClass operator - (const complexClass& other) {
		complexClass bufferNum(this->re - other.re, this->im - other.im);
		return bufferNum;
	}
	complexClass operator * (const complexClass& other) {
		complexClass bufferNum((this->re * other.re) - (this->im * other.im), (this->re * other.im) + (this->im * other.re));
		return bufferNum;
	}
	complexClass operator / (const complexClass& other) {
		complexClass bufferNum(((this->re * other.re) + (this->im * other.im)) / (pow(other.re, 2) + pow(other.im, 2)),
			((this->im * other.re) - (this->re * other.im)) / ((pow(other.re, 2) + pow(other.im, 2))));
		return bufferNum;
	}
	friend ostream& operator<< (ostream& out, const complexClass& complexNum);

};


#endif complex
