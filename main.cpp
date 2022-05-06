#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "complex.h"

using namespace std;

int main() {

	cout << "N1\n";
	complexClass a(5, 7);
	complexClass b(-4, 10);

	cout << a + b;
	cout << a - b;
	cout << a * b;
	cout << a / b << endl;

	cout << "N2\n";
	ifstream fin("complexFile.txt");
	int n = 0;
	char jj[1024];
	std::string l;
	if (!fin.is_open()) return -1;
	while (!fin.eof()) {
		fin.getline(jj, 1024, '\n');
		n++;
	}

	fin.close();
	std::ifstream fin2("complexFile.txt");
	if (!fin2.is_open()) return -1;

	complexClass* p = new complexClass[n];
	int counter = 0;
	while (getline(fin2, l)) {
		std::string qq, gg;
		double reI = 0, imI = 0;
		bool qw = false;
		for (int i = 0; i < l.size(); ++i) {
			if (l[l.size() - 1] != 105) {
				qq += l[i];
				continue;
			}
			if (l[i] == 32) continue;
			if (i != 0 and (l[i] == 43 or l[i] == 45)) qw = true;
			if (qw == false) {
				qq += l[i];
			}
			else {
				if (l[i] == 43) continue;
				if (l[i] == 105) break;
				gg += l[i];
			}
		}
		complexClass xc(stod(qq), stod(gg));
		p[counter] = xc;
		counter++;
	}


	double ma= 0;
	for (int i = 0; i < n; ++i) if (p[i].moduleFoo() > ma) ma= p[i].moduleFoo();

	cout << ma<< std::endl;
	return 0;


}