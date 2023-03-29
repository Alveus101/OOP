/*
Vlasnik ste niza garaža u velegradu Zagrebu i iznajmljujete ih za razumnu cijenu, i već vam je pomalo nespretno voditi evidenciju o tome koje sve garaže postoje i tko ima koje ključeve, pa ste se odlučili baciti na posao i napraviti C++ program koji će vam u tome pomoći.

Odlučili ste definirati niz garaža, i u svakoj garaži bilježiti niz ključeva koji su vaši (kako vam ne bi nestali).

Klasa Garaza ima sljedeća svojstva:

veličinu (širina x duljina)
cijenu iznajmljivanja
lokaciju
niz ključeva koji su vaši
Klasa Kljuc ima sljedeća svojstva:

ime i prezime osobe kod koje je ključ
U main programu potrebno je od korisnika tražiti unos broja N, nakon kojeg se unose podaci o N garaža. Nakon što se unesu sva polja, potrebno je tražiti unos broja M, koji označava broj ključeva, te je potrebno unijeti tih M ključeva (neka garaža može imati više ključeva).

Primjer izvođenja:

Unesite broj garaža (N):2
 Unesite velicinu, lokaciju i cijenu za 1. garazu:
 10 20
 Konavoska 3
 500
 Unesite velicinu, lokaciju i cijenu 2. garazu:
 15 25
 Konavoska 3b
 440
 Unesite broj kljuceva (M): 1
 Unesite redni broj garaze kojoj pripada 1. kljuc: 2
 Unesite ime vlasnika kljuca: Ana Anic
 
 Ispis garaza i kljuceva:
 1. Konavoska 3 10x20 - kljucevi:
 2. Konavoska 3b 15x25 - kljucevi: Ana Anic
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Kljuc {
public:
	string ime;
};

class Garaza {
public:
	int sirina;
	int duljina;
	int cijena;
	string lokacija;
	vector <Kljuc> kljucevi;
};


int main() {
	
	vector<Garaza> G;
	Garaza temp;
	Kljuc kljuc;
	int n, m, id;

	cout << "Unesite broj garaza (N): ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Unesite velicinu, lokaciju i cijenu za " << i+1 << ". garazu: " << endl;
		cin >> temp.sirina;
		cin >> temp.duljina;
		cin.ignore();
		getline(cin, temp.lokacija);
		cin >> temp.cijena;

		G.push_back(temp);
	}

	cout << "Unesite broj kljuceva (M): ";
	cin >> m;

	for (int i = 0; i < m; i++) {
		cout << "Unesite redni broj garaze kojoj pripada " << i + 1 << ". kljuc: ";
		cin >> id;

		cout << "Unesite ime vlasnika kljuca: ";

		cin.ignore();
		getline(cin, kljuc.ime);
		
		G[id-1].kljucevi.push_back(kljuc);
	}

	cout << "Ispis garaza i kljuceva:" << endl;
	for (int i = 0; i < n; i++) {
		
		cout << i+1 << ". " << G[i].lokacija << " " << G[i].sirina << "x" << G[i].duljina << " - kljucevi: ";
		
		for (int j = 0; j < G[i].kljucevi.size(); j++) {
			cout << G[i].kljucevi[j].ime << " ";
		}

		cout << "\n";
	}

	return 0;
}
