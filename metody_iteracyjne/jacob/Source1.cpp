#include <iostream>
#include <locale.h>
#include <fstream>
#include <cstdlib>

using namespace std;

////////////////////////////////funkcje pomocnicze/////////////////////////////

void wypiszwynik(int wiersze, float* rozwiazanie) {
	for (int k = 0; k < wiersze; k++) {
		cout << "x" << k + 1 << "= " << rozwiazanie[k] << endl;

	}
	cout << endl;
}

void wypisz(float** macierz, int wiersze, int kolumny) {
	for (int i = 0; i < wiersze; i++) {
		for (int j = 0; j < kolumny; j++) {
			cout << macierz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void czyszczenie(int wiersze, float* rozwiazanie) {
	for (int k = 0; k < wiersze; k++) {
		rozwiazanie[k] = 0;

	}
}


/////////////////////////////nowe zadanie//////////////////////////////////////////////////

void jacobiego(float** macierz, int wiersze, float* rozwiazanie) {
	int iteracje;
	cout << "PODAJ ILOSC ITERACJI" << endl;
	cin >> iteracje;
	cout << endl;
	int kolumny = wiersze + 1;
		float* rozwpom = rozwiazanie;
	for (int k = 0; k < iteracje; k++) {


		for (int i = 0; i < wiersze; i++) {
			float wynik = macierz[i][kolumny - 1];

			for (int j = 0; j < (kolumny - 1); j++) {
				if (i != j) {
					wynik = wynik - (rozwiazanie[j] * macierz[i][j]);
				}
			}
			wynik = wynik / macierz[i][i];
			rozwpom[i] = wynik;

		}

		for (int p = 0; p < wiersze; p++) {
			rozwiazanie[p] = rozwpom[p];
		}

		cout << "ITERACJA " << k + 1 << ":" << endl;
		wypiszwynik(wiersze, rozwiazanie);
	}

	cout << "KONCOWY WYNIK" << endl;
	wypiszwynik(wiersze, rozwiazanie);

}

void gs(float** macierz, int wiersze, float* rozwiazanie) {
	int iteracje;
	cout << "PODAJ ILOSC ITERACJI" << endl;
	cin >> iteracje;
	cout << endl;
	int kolumny = wiersze + 1;
float* rozwpom = rozwiazanie;
	for (int k = 0; k < iteracje; k++) {
		

		for (int i = 0; i < wiersze; i++) {
			float wynik = macierz[i][kolumny - 1];

			for (int j = 0; j < i; j++) {

				wynik = wynik - (rozwpom[j] * macierz[i][j]);
			}
			
			
			for (int j = i+1; j < (kolumny - 1); j++) {
				
				wynik = wynik - (rozwiazanie[j] * macierz[i][j]);
				
			}
			wynik = wynik / macierz[i][i];
			rozwpom[i] = wynik;

		}

		for (int p = 0; p < wiersze; p++) {
			rozwiazanie[p] = rozwpom[p];
		}

		cout << "ITERACJA " << k + 1 << ":" << endl;
		wypiszwynik(wiersze, rozwiazanie);
	}

	cout << "KONCOWY WYNIK" << endl;
	wypiszwynik(wiersze, rozwiazanie);

}



///////////////////////////////////stare zadanie///////////////////////////////////////////////////

void trojkatna(float** macierz, int wiersze, int kolumny) {
	for (int i = 1; i < wiersze; i++) {
		for (int j = i; j < wiersze; j++) {
			float pom = macierz[j][i - 1] / macierz[i - 1][i - 1];
			for (int k = i - 1; k < kolumny; k++) {
				float pom1 = macierz[j][k];
				macierz[j][k] = (pom1 - (pom * macierz[i - 1][k]));
			}
		}

	}
}

void wyliczenie(float** macierz, int wiersze, int kolumny, float* rozwiazanie) {

	for (int i = wiersze - 1; i >= 0; i--) {
		float wynik = macierz[i][kolumny - 1];
		for (int j = wiersze - 1; j >= i + 1; j--) {
			wynik -= (rozwiazanie[j] * macierz[i][j]);
		}
		rozwiazanie[i] = wynik / macierz[i][i];
	}

	wypiszwynik(wiersze, rozwiazanie);

}

void gauss(float** macierz, int wiersze, int kolumny, float* rozwiazanie) {
	cout << "MACIERZ TROJKATNA" << endl;
	trojkatna(macierz, wiersze, kolumny);
	wypisz(macierz, wiersze, kolumny);
	cout << "WYLICZONE NIEWIADOME" << endl;
	wyliczenie(macierz, wiersze, kolumny, rozwiazanie);
}


int main() {

	cout << "PODAJ ILOSC ROWNAN" << endl;
	int wiersze;
	cin >> wiersze;
	int kolumny = wiersze + 1;
	float** macierz, * rozwiazania;


	macierz = new float* [wiersze];
	rozwiazania = new float[wiersze];

	for (int i = 0; i < wiersze; i++) {
		macierz[i] = new float[wiersze + 1];
	}


	cout << "PODAJ KOLEJNE WSPOLCZYNNIKI UKLADU ROWNAN" << endl;
	for (int i = 0; i < wiersze; i++) {
		for (int j = 0; j <= wiersze; j++) {

			cin >> macierz[i][j];
		}
	}
	cout << endl;



	cout << "MACIERZ WYJSCIOWA" << endl;
	wypisz(macierz, wiersze, kolumny);


	cout << "METODA ELIMINACJI GAUSSA" << endl;
	gauss(macierz, wiersze, kolumny, rozwiazania);
	czyszczenie(wiersze, rozwiazania);

	cout << "METODA JACOBIEGO"<<endl;
	jacobiego(macierz, wiersze, rozwiazania);
	czyszczenie(wiersze, rozwiazania);

	cout << "METODA GAUSSA-SEIDLA" << endl;
	gs(macierz, wiersze, rozwiazania);
	czyszczenie(wiersze, rozwiazania);

	return 0;

}