/*
ZADATAK:
Kompleksni broj
Uvod u klase, atributi, dinamički nizovi, vektori, sortiranje
Napišite program koji u dinamički alocirano polje učitava N kompleksnih brojeva te ih ispisuje sortirane po vrijednosti njihovih modula (od najmanjeg prema najvećem). 
•	Kompleksni broj treba predstaviti klasom Kompleksni koja sadrži realni i imaginarni dio (realni brojevi). 
•	Modul kompleksnog broja je udaljenost kompleksnog broja od ishodišta i treba se računati globalnom funkcijom Modul. 
•	Za sortiranje kompleksnih brojeva napišite funkciju Sortiraj koja će sortirati kompleksne brojeve upotrebom BubbleSort algoritma.

Primjer izvođenja
Unesi N: 3
niz[0].re = 3
niz[0].im = -1
niz[1].re = 1
niz[1].im = 1
niz[2].re = 2
niz[2].im = -3
Z(1+1)  Modul: 1.41421
Z(3-1)  Modul: 3.16228
Z(2-3)  Modul: 3.60555

Nakon što ste zadatak riješili upotrebom dinamički alociranog polja zamijenite ga vektorom kompleksnih brojeva te sortirajte upotrebom funkcije std::sort (zaglavlje algorithm).
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Kompleksni{
public:
	int re;
	int im;
	Kompleksni() {}
	Kompleksni(int _re, int _im) : re(_re), im(_im) {}

};

double Modul(Kompleksni Z) {
	return sqrt(pow(Z.re, 2) + pow(Z.im, 2));
}

bool Usporedba(Kompleksni Z1, Kompleksni Z2) {
	return Modul(Z1) < Modul(Z2);
}

void Sortiraj(int n, Kompleksni* niz) {

	Kompleksni temp;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n - i - 1; j++) {
			
			if (Modul(niz[j]) > Modul(niz[j + 1])) {
				temp = niz[j];
				niz[j] = niz[j + 1];
				niz[j + 1] = temp;
			}

		}
	}
}


// ========================================
// Prvi dio zadatka
// ========================================


/*int main() {

	int n, im, re;
	
	cout << "Unesi N: ";
	cin >> n;

	Kompleksni* niz = new Kompleksni[n];

	for (int i = 0; i < n; i++) {
		cout << "niz[" << i << "].re = ";
		cin >> re;

		cout << "niz[" << i << "].im = ";
		cin >> im;

		niz[i] = Kompleksni(re, im);
	}

	Sortiraj(n, niz);

	for (int i = 0; i < n; i++) {
		cout << "Z(" << niz[i].re << "," << niz[i].im << ") Modul: " << Modul(niz[i]) << endl;
	}
}*/

// ========================================
// Drugi dio sa vektorom i sort
// ========================================


int main(){
	int n, im, re;

	cout << "Unesi N: ";
	cin >> n;

	vector<Kompleksni> niz;

	for (int i = 0; i < n; i++) {
		cout << "niz[" << i << "].re = ";
		cin >> re;

		cout << "niz[" << i << "].im = ";
		cin >> im;

		niz.push_back(Kompleksni(re, im));
	}

	sort(niz.begin(), niz.end(), Usporedba);

	for (int i = 0; i < n; i++) {
		cout << "Z(" << niz[i].re << "," << niz[i].im << ") Modul: " << Modul(niz[i]) << endl;
	}
}
