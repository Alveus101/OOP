/*
ZADATAK:
Najstarija osoba
Skrivanje podataka, get i set, const

Napišite klasu Osoba koja ima sljedeće podatkovne članove: Ime (string), Prezime (string), GodinaRodjenja (int). 
Svi podatkovni članovi trebaju imati privatno pravo pristupa. Potrebno je osigurati da ime i prezime imaju najmanju 
duljinu od 3 znaka, te da godina rođenja nije manja od 1900. Sukladno tome u klasi Osoba dodajte sve potrebne get i 
set metode te pripadne const deklaracije za metode koje bi se smjele pozivati nad konstantnim objektima te klase.

Unutar projekta potrebno je deklaraciju klase Osoba, njenih metoda i podatkovnih članova smjestiti u Osoba.h datototeku, 
dok tijela metoda smjestiti u Osoba.cpp datoteku. U projekt dodajte novu cpp datoteku u kojoj se treba nalaziti funkcija 
main. Unutar nje kreirajte polje od 5 objekata tipa Osoba te inicijalizirajte vrijednosti svih objekata preko konzole 
(tipkovnice). Na kraju, program treba ispisati koja je najstarija od unesenih osoba.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_OSOBA 5

class Osoba {
	string Ime;
	string Prezime;
	int GodinaRodjenja;

public:
	Osoba(){}

	void setIme(string ime);
	void setPrezime(string prezime);
	void setGodinuR(int godina);

	string getIme() const;
	string getPrezime() const;
	int getGodinuR() const;

};

void Osoba::setIme(string ime) {
	if (ime.size() < 3)
		cout << "Ime mora imati najmanje 3 slova." << endl;
	else
		Ime = ime;
}

void Osoba :: setPrezime(string prezime) {
	if (prezime.size() < 3)
		cout << "Prezime mora imati najmanje 3 slova." << endl;
	else
		Prezime = prezime;
 }

void Osoba::setGodinuR(int godina) {
	if (godina < 1900)
		cout << "Godina ne smije biti manja od 1900." << endl;
	else
		GodinaRodjenja = godina;
}

string Osoba::getIme() const {
	return Ime;
}

string Osoba::getPrezime() const {
	return Prezime;
}

int Osoba::getGodinuR() const {
	return GodinaRodjenja;
}

int main() {
	Osoba polje[MAX_OSOBA];
	string ime, prezime;
	int godina = 0, najstarijaGodina = 2023, indeksNajstarije = 0;

	for (int i = 1; i <= MAX_OSOBA; i++) {
		cout << "===== Unosis podatke za osobu broj " << i << " =====" << endl;
		
		cout << "Unesi ime: ";
		cin >> ime;
		polje[i-1].setIme(ime);

		cout << "Unesi prezime: ";
		cin >> prezime;
		polje[i-1].setPrezime(prezime);

		cout << "Unesi godinu rodjenja: ";
		cin >> godina;
		polje[i-1].setGodinuR(godina);

		if (godina < najstarijaGodina) {
			najstarijaGodina = godina;
			indeksNajstarije = i-1;
		}
	}

	cout << "Najstarija osoba je " << polje[indeksNajstarije].getIme() << " " << polje[indeksNajstarije].getPrezime() << " sa " << 2023 - polje[indeksNajstarije].getGodinuR() << " godine!" << endl;

}
