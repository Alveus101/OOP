/*
ZADATAK:
Račun i artikli
Vektor, konstruktor
Potrebno je napisati program za evidenciju računa. Primjerice, u dućanu svaki kupac ima račun s jedinstvenim rednim brojem, 
a na tom računu se nalazi popis kupljenih stavki (naziv, količina, jedinična cijena). Slijedeći programski odsječak u nastavku 
napišite sve potrebne klase i metode kojima se dobije očekivano ponašanje programskog koda.

int main(){
	Kupac Ante(Racun(1)); // Ante ima račun broj 1
	Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg
	Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg
	Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca
	cout << "Ukupno: " << Ante.racun.ukupnaCijena << " kn" << endl; // 41 kn

	// U nastavku ispišite koji je najskuplji artikl kojeg je Ante platio 
    //    (naziv i ukupna cijena). Npr.
	
	//  Najskuplje placeni artikl je Coca cola 2l (20kn)

	return 0;
}
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Artikl {
public:
	string ime;
	int kolicina;
	double cijena;

	Artikl() {}
	Artikl(string _ime, int _kolicina, double _cijena) : ime(_ime), kolicina(_kolicina), cijena(_cijena) {}
};

class Racun {
public:
	int brojRacuna;
	double ukupnaCijena = 0;
	vector<Artikl> stavke;

	Racun() {}
	Racun(int br) : brojRacuna(br) {}
	
	void dodaj(Artikl a) {
		stavke.push_back(a);
		ukupnaCijena += a.cijena * a.kolicina;
	}

	void NajskupljiArtikl() {
		Artikl najskuplji("NONE", 1, 0);

		for (int i = 0; i < stavke.size(); i++) {
			if (stavke[i].cijena > najskuplji.cijena) {
				najskuplji = stavke[i];
			}
		}

		cout << "Najskuplje placeni artikl je " << najskuplji.ime << " (" << najskuplji.cijena*najskuplji.kolicina << "kn)" << endl;
	}

};

class Kupac {
public:

	Racun racun;

	Kupac(Racun _r) : racun(_r) {}
};

int main() {
	Kupac Ante(Racun(1)); // Ante ima račun broj 1
	Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg
	Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg
	Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca
	cout << "Ukupno: " << Ante.racun.ukupnaCijena << " kn" << endl; // 41 kn

	/* U nastavku ispišite koji je najskuplji artikl kojeg je Ante platio
		  (naziv i ukupna cijena). Npr.

	   Najskuplje placeni artikl je Coca cola 2l (20kn)
	*/

	Ante.racun.NajskupljiArtikl();
	return 0;
}
