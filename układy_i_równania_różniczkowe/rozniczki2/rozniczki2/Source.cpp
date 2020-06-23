#include <iostream>
#include <locale.h>
#include <fstream>
#include <cstdlib>

using namespace std;


double f(double x, double y, double u) {
	double wynik = (-1)*y;
	return wynik;
}
double g(double x, double y, double u) {
	double wynik = u;
	return wynik;
}


void  euler(double x0, double y0, double u0, double h, int ilosc) {
	double 	x = x0;
	double  y = y0;
	double u = u0;
	double ypom;

	while(x<=ilosc) {
		fstream plik;
		plik.open("EULER2.txt", ios::out | ios::app);
		if (plik.good() == true)
		{
			plik << x << ";" << y << ";" << u << endl;
			plik.close();
		}
		ypom = y;
		y = y + u * h;
		u = u + f(x, ypom, u) * h;
		x = x + h;

	}
}


void RK4(double x0, double y0, double u0, double h) {
	double x = x0;
	double y = y0;
	double u = u0;
	
	double k1;
	double k2;
	double k3;
	double k4;
	
	double q1;
	double q2;
	double q3;
	double q4;


	while(x<=20) {
		fstream plik;
		plik.open("RK4zad2.txt", ios::out | ios::app);
		if (plik.good() == true)
		{
			plik << x << ";" << y << ";" << u << endl;
			plik.close();
		}

		k1 = h * g(x, y, u);
		q1 = h * f(x, y, u);
		k2 = h * g((x + 0.5 * h), (y + 0.5 * k1), (u + 0.5 * q1));
		q2 = h * f((x + 0.5 * h), (y + 0.5 * k1), (u + 0.5 * q1));
		k3 = h * g((x + 0.5 * h), (y + 0.5 * k2), (u + 0.5 * q2));
		q3 = h * f((x + 0.5 * h), (y + 0.5 * k2), (u + 0.5 * q2));
		k4 = h * g((x + h), (y + k3), (u + q3));
		q4 = h * f((x + h), (y + k3), (u + q3));

		y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
		u = u + (1.0 / 6.0) * (q1 + 2 * q2 + 2 * q3 + q4);
		x = x + h;

	}
}


int main() {
	euler(0, 10, 0, (0.2), 16);
	RK4(0, 10, 0, (16.0/20.0));


	return 0;
}