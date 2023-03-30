/*
Zadatak: https://i.imgur.com/qfxqeAI.png
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

class Knjiga {
public:
	string naslov, autor;
	int posudjeno, dostupno;

	Knjiga(string _naslov, string _autor, int _posudjeno, int _dostupno) {
		naslov = _naslov;
		autor = _autor;
		posudjeno = _posudjeno;
		dostupno = _dostupno;
	}
};

bool usporedba(Knjiga a, Knjiga b) {
	return a.posudjeno > b.posudjeno;
}

class Knjiznica {
public:
	string naziv, adresa;
	vector<Knjiga> knjige;
	
	Knjiznica(string _naziv, string _adresa, Knjiga _knjiga) {
		naziv = _naziv;
		adresa = _adresa;
		knjige.push_back(_knjiga);
	}

	vector <Knjiga> PriKrajuZaliha();

	void Sortiraj() {
		sort(knjige.begin(), knjige.end(), usporedba);
	}
};

vector <Knjiga> Knjiznica::PriKrajuZaliha() {

	vector <Knjiga> pri_kraju;

	for (int i = 0; i < knjige.size(); i++) {
		if (knjige[i].dostupno < 10) {
			pri_kraju.push_back(knjige[i]);
		}
	}

	return pri_kraju;
}

Knjiznica NajvisePrimjeraka(vector<Knjiznica> popis_knjiznica) {
	int ind = 0, max = 0, uk = 0;

	for (int i = 0; i < popis_knjiznica.size(); i++) {
		for (int j = 0; j < popis_knjiznica[i].knjige.size(); j++) {
			uk += popis_knjiznica[i].knjige[j].dostupno;
		}
		if (uk > max) {
			max = uk;
			ind = i;
		}
	}

	return popis_knjiznica[ind];
}

int main() {

	Knjiga knjiga("Knjiga 1", "Autor 1", 20, 15);
	Knjiznica knjiznica("Knjiznica 1", "Adresa 1", knjiga);
	
	/*
	// PriKrajuZaliha test
	vector<Knjiga> pri_kraju_zaliha = knjiznica.PriKrajuZaliha();

	for (int i = 0; i < pri_kraju_zaliha.size(); i++) {
		cout << "Knjiga pri kraju zaliha: " << pri_kraju_zaliha[i].naslov << " - " << pri_kraju_zaliha[i].autor << " Dostupno: " << pri_kraju_zaliha[i].dostupno << endl;
	}

	// Sortiraj test

	Knjiga knjiga_nova("Mein Kampf", "Hitler", 35, 5);
	knjiznica.knjige.push_back(knjiga_nova);

	for (int i = 0; i < knjiznica.knjige.size(); i++) {
		cout << knjiznica.knjige[i].naslov << " - " << knjiznica.knjige[i].autor << " Posudjeno: " << knjiznica.knjige[i].posudjeno << endl;
	}

	cout << "Sortiranje..." << endl;
	knjiznica.Sortiraj();

	for (int i = 0; i < knjiznica.knjige.size(); i++) {
		cout << knjiznica.knjige[i].naslov << " - " << knjiznica.knjige[i].autor << " Posudjeno: " << knjiznica.knjige[i].posudjeno << endl;
	}

	// NajvisePrimjeraka test

	vector<Knjiznica> vise_knjiznica;
	vise_knjiznica.push_back(knjiznica);

	Knjiga knjiga_druga("Knjiga 2", "Autor 2", 5, 20);
	Knjiznica knjiznica_druga("Knjiznica 2", "Adresa 2", knjiga_druga);
	vise_knjiznica.push_back(knjiznica_druga);

	cout << NajvisePrimjeraka(vise_knjiznica).naziv << endl;
	*/

	return 0;
}
