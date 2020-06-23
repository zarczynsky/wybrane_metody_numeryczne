#include <iostream>
#include <locale.h>
#include <fstream>
#include <cstdlib>

using namespace std;


double f(double x, double y) {
	double wynik = (-2) * x * y;
	return wynik;
}


void  euler(double x0, double y0, double h, int ilosc) {
double 	x = x0;
double  y = y0;
for (int i = 0; i < ilosc; i++) {
	fstream plik;
	plik.open("EULER.txt", ios::out | ios::app);
	if (plik.good() == true)
	{
		plik << x <<";"<<y<< endl;
		plik.close();
	}
	y = y + f(x, y) * h;
	x = x + h;
	
}
}

void RK4(double x0, double y0, double h, int ilosc) {
	double x = x0;
	double y = y0;
	double k1;
	double k2;
	double k3;
	double k4;

	for (int i = 0; i < ilosc; i++) {
		fstream plik;
		plik.open("RK4.txt", ios::out | ios::app);
		if (plik.good() == true)
		{
			plik << x << ";" << y << endl;
			plik.close();
		}

		k1 = h * f(x, y);
		k2 = h * f((x + 0.5 * h), (y + 0.5 * k1));
		k3 = h * f((x + 0.5 * h), (y + 0.5 * k2));
		k4 = h * f((x + h), (y + k3));
		y = y + (1.0/6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
		x = x + h;

	}
}


int main() {
	//euler(0, 1, 0.1, 21);
	RK4(0, 1, 0.1, 21);


	return 0;
}