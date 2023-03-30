/*
Zadatak: https://i.imgur.com/sz1XqAl.png
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

class Proizvod {
public:
	int sifra, cijena, prodano;
	string naziv;

	Proizvod( int _sifra, string _naziv, int _cijena, int _prodano) {
		sifra = _sifra;
		naziv = _naziv;
		cijena = _cijena;
		prodano = _prodano;
	}
};

bool usporedba(Proizvod a, Proizvod b) {
	return a.prodano > b.prodano;
}

class Ducan {
public:
	string naziv, adresa;
	vector<Proizvod> proizvodi;

	Ducan(string _naziv, string _adresa, vector<Proizvod> _proizvodi) {
		naziv = _naziv;
		adresa = _adresa;
		proizvodi = _proizvodi;
	}
	
	vector<Proizvod> SkupiProizvodi();

	void Sortiraj() {
		sort(proizvodi.begin(), proizvodi.end(), usporedba);
	}
};

vector<Proizvod> Ducan::SkupiProizvodi() {

	vector<Proizvod> skupi;

	for (int i = 0; i < proizvodi.size(); i++) {
		if (proizvodi[i].cijena > 100) {
			skupi.push_back(proizvodi[i]);
		}
	}

	return skupi;
}

Ducan NajuspjesnijiDucan(vector<Ducan> ducani) {
	int ind = 0, max = 0, uk = 0;

	for (int i = 0; i < ducani.size(); i++) {
		for (int j = 0; j < ducani[i].proizvodi.size(); j++)
			uk += ducani[i].proizvodi[j].prodano * ducani[i].proizvodi[j].cijena;
		if (uk > max) {
			max = uk;
			ind = i;
		}
	}

	return ducani[ind];
}

int main() {

	vector<Proizvod> proizvodi = { Proizvod(100, "Kurh", 10, 2500), Proizvod(101, "Mlijeko", 8, 3000) };
	Ducan ducan("Ducan", "Rupertova 18, Sisak", proizvodi);

	/*
	vector<Ducan> lista_ducana;
	vector<Proizvod> skupi;

	// Skupi proizvodi test

	lista_ducana.push_back(ducan);

	for (int i = 0; i < lista_ducana.size(); i++) {
		skupi = lista_ducana[i].SkupiProizvodi();
		
		for (int j = 0; j < skupi.size(); j++) {
			cout << skupi[j].naziv << " - " << skupi[j].cijena << endl;
		}
	}

	// Sort test

	for (int i = 0; i < ducan.proizvodi.size(); i++) {
		cout << ducan.proizvodi[i].naziv << " " << ducan.proizvodi[i].cijena << " " << ducan.proizvodi[i].prodano << endl;
	}

	cout << "Sortiranje..." << endl;
	ducan.Sortiraj();
	
	for (int i = 0; i < ducan.proizvodi.size(); i++) {
		cout << ducan.proizvodi[i].naziv << " " << ducan.proizvodi[i].cijena << " " << ducan.proizvodi[i].prodano << endl;
	}

	// Najuspjesniji Ducan test

	cout << NajuspjesnijiDucan(lista_ducana).naziv << endl;
	*/

	return 0;
}
