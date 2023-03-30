/*
Zadatak: https://i.imgur.com/DdcpHRP.png
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

class Automobil {
public:
	string naziv;
	string gorivo;
	int ks;
	int cijena;

	Automobil(string _naziv, string _gorivo, int _ks, int _cijena) {
		naziv = _naziv;
		gorivo = _gorivo;
		ks = _ks;
		cijena = _cijena;
	}
};

bool usporedba(Automobil a, Automobil b) {
	return a.ks < b.ks;
}

class AutoSalon {
public:
	string naziv;
	string adresa;
	vector <Automobil> auti;
	
	AutoSalon(string _naziv, string _adresa, vector<Automobil> _auti) {
		naziv = _naziv;
		adresa = _adresa;
		auti = _auti;
	}

	void Sortiraj() {
		sort(auti.begin(), auti.end(), usporedba);
	}

	vector<Automobil> NajsnaznijiMotori();
};

vector<Automobil> AutoSalon::NajsnaznijiMotori() {
	vector<Automobil> najsnazniji;

	for (int i = 0; i < auti.size(); i++) {
		if (auti[i].ks > 100) {
			najsnazniji.push_back(auti[i]);
		}
	}
	return najsnazniji;
}

AutoSalon NajskupljiAutoSalon(vector<AutoSalon> autosaloni) {

	int najskuplji = 0;
	int uk = 0, avg = 0, max = 0;

	for (int i = 0; i < autosaloni.size(); i++) {
		for (int j = 0; j < autosaloni[i].auti.size(); j++) {
			uk = autosaloni[i].auti[j].cijena;
		}
		avg = uk / autosaloni[i].auti.size();
		if (avg > max) {
			max = avg;
			najskuplji = i;
		}
	}

	return autosaloni[najskuplji];
}

int main() {

	/*vector<AutoSalon> niz;*/

	vector<Automobil> auti = { Automobil("BMW 118i", "benzin", 150, 225000), Automobil("Dacia Duster", "plin", 91, 114200), Automobil("Citroen C3", "Diesel", 110, 127000) };
	AutoSalon autosalon("Auto salon", "Rijecka cesta 200, Rijeka", auti);

	/*niz.push_back(autosalon);

	vector <Automobil> najsnazniji = autosalon.NajsnaznijiMotori();
	for (int i = 0; i < najsnazniji.size(); i++) {
		cout << najsnazniji[i].naziv << endl;
	}

	cout << NajskupljiAutoSalon(niz).naziv;*/

	return 0;
}
