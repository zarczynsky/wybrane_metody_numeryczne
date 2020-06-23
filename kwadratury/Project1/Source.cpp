#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;


float f1(float x) {
	float wynik;
	wynik = x * x * x + 2 * x * x - 4 * x;
	return wynik;
}

float f2(float x) {
	float wynik;
	wynik = 1/( 2 * x + 1);
	return wynik;
}

float trapez(float a, float b, float pom1, float pom2) {
	float s;	
	s = (a - b) / 2 * (pom1 + pom2);
	return s;
}



float parabola(float a, float b, float pom1, float pom2, float pom3) {
	float s;
	s = (a - b) / 6 * (pom1 + pom2 + 4*pom3);
	return s;

}

float calytrapez(float a, float b, int funkcja) {

	float pom1;
	float pom2;
	if (funkcja == 1) {
		pom1 = f1(a);
		pom2 = f1(b);
	}
	else if(funkcja==2) {
		pom1 = f2(a);
		pom2 = f2(b);
	}
	float wynik;
	wynik = trapez(a, b, pom1, pom2);
	return wynik;
}

float calaparabola(float a, float b, int funkcja) {

	float pom1;
	float pom2;
	float pom3;
	if (funkcja == 1) {
		pom1 = f1(a);
		pom2 = f1(b);
		pom3 = f1((a + b) / 2);
	}
	else if (funkcja == 2) {
		pom1 = f2(a);
		pom2 = f2(b);
		pom3 = f2((a + b) / 2);
	}
	float wynik;
	wynik = parabola(a, b, pom1, pom2, pom3);
	return wynik;
}


float zlozonytrapez(float a, float b, float pom1, float pom2, float pom3, float n) {
	float s;
	s = ((b - a)/n)*(0.5*(pom1+pom2)+pom3);
	return s;
}

float petla(int funkcja, float a, float b, float n){
float h;
h=( b - a )/n;
float pomocnicza;
pomocnicza=a+h;
float wynik=0;
for (int i = 1; i < n ; i++) {
	if (funkcja == 1) {
		wynik = wynik + f1(pomocnicza);
		pomocnicza = pomocnicza + h;
	}
	else if (funkcja == 2) {
		wynik = wynik + f2(pomocnicza);
		pomocnicza = pomocnicza + h;
		
	}
}
return wynik;
}

float calytrapezzlozony(float a, float b, int funkcja, float n) {
	float pom1;
	float pom2;
	float pom3;

	if (funkcja == 1) {
		pom1 = f1(a);
		pom2 = f1(b);
		pom3 = petla(funkcja, a, b, n);
	}
	if (funkcja == 2) {
		pom1 = f2(a);
		pom2 = f2(b);
		pom3 = petla(funkcja, a, b, n);
	}

	float wynik;
	wynik = zlozonytrapez(a, b, pom1, pom2, pom3, n);
	return wynik;
}

int main() {
	float trapeznr1;
	float trapeznr2;
	float parabolanr1;
	float parabolanr2;
	float zloztrapeznr1;
	float zloztrapeznr2;
	trapeznr1 = calytrapez(1, 0, 1);
	trapeznr2 = calytrapez(2, 0, 2);
	parabolanr1 = calaparabola(1, 0, 1);
	parabolanr2 = calaparabola(2, 0, 2);
	zloztrapeznr1 = calytrapezzlozony(0, 1, 1, 10);
	zloztrapeznr2 = calytrapezzlozony(0, 2, 2, 5);
	cout << "WZOR TRAPEZOW:" << endl << "Funkcja nr 1:" << trapeznr1 << endl << "Funkcja nr 2:" << trapeznr2 << endl << endl;
	cout << "WZOR PARABOL:" << endl << "Funkcja nr 1:" << parabolanr1 << endl <<"Funkcja nr 2:"<< parabolanr2 << endl << endl;
	cout << "ZLOZONY WZOR TRAPEZOW:"<< endl << "Funkcja nr 1:" << zloztrapeznr1 <<endl << "Funkcja nr 2:" << zloztrapeznr2 << endl <<endl;
	return 0;

}