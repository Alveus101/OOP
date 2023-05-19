/*
ZADATAK:
Karte
Vektor, konstruktor, algoritmi
U kartaškom špilu se nalaze 52 karte a svaka od karti je označena brojem 1-52. Napišite program koji će za N igrača (N <= 13) podijeliti po 4 karte iz kartaškog špila. Prilikom kreiranja kartaškog špila sve karte mogu biti poredane po redu (1-52) ili izmiješane slučajnim redoslijedom (random_shuffle, zaglavlje algorithm). 
Na početku programa potrebno je unijeti N igrača te kreirati novi (izmiješani) špil karata. Upotrebom metode void Spil::Podijeli4Karte(Igrac *igrac) svakom od igrača treba podijeliti po 4 karte sa vrha špila. Svaki igrač ima svoje ime te popis karti koje su mu podijeljene. Program treba ispisati karte koje su podijeljene svakom od igrača a zatim i karte koje su ostale u špilu.

Primjer izvođenja (izmiješani špil karata):
Unesi broj igraca: 2
Unesi ime 1.igraca: Ante
Unesi ime 2.igraca: Ivica

Karte u spilu (52):
10      7       5       6       4       41      26      8       31      42
2       33      47      37      14      16      51      35      24      38
18      25      21      36      11      49      52      29      45      13
19      44      43      32      12      3       30      17      34      9
40      22      1       20      27      39      15      46      50      23
48      28

Ante je dobio sljedece karte:   10      7       5       6
Ivica je dobio sljedece karte:  4       41      26      8


Preostale karte u spilu (44):
31      42      2       33	    47      37      14      16	    51     35      
24      38      18      25  	21      36      11      49	    52     29      
45      13      19      44   	43      32      12      3	    30     17      
34       9      40      22   	1       20      27      39	    15     46      
50      23      48      28      
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Igrac {
public:
	string ime;
	vector<int> k;

	Igrac(string _ime) : ime(_ime) {}
};

class Spil {
public:
	vector<int> karte;

	Spil() {};

	void Podijeli4Karte(Igrac* igrac) {

		cout << "\n" << igrac->ime << " je dobio sljedece karte: ";
		for (int i = 0; i < 4; i++) {
			igrac->k.push_back(karte[0]); // U igracu se daje karta sa vrha spila
			cout << karte[0] << "\t";	  // Ispis te karte
			karte.erase(karte.begin());	  // Brisanje karte sa vrha spila
		}
	}
};

int main() {
	int n = 0;
	string ime;

	vector<Igrac> igraci;
	Spil s;

	// Unos igraca koji mora biti izmedju 1 i 13
	while (n < 1 || n > 13) {
		cout << "Unesi broj igraca: ";
		cin >> n;
	}

	// Unos imena za svakog igraca
	for (int i = 0; i < n; i++) {
		cout << "Unesi ime" << i <<".igraca: ";
		cin >> ime;
		igraci.push_back(Igrac(ime));
	}

	// Generiranje kartaskog spila
	cout << "Karte u spilu (52):" << endl;
	for (int i = 1; i <= 52; i++) {
		s.karte.push_back(i);

		cout << i << "\t";
		if (i % 10 == 0) cout << "\n";
	}

	// Dijeljenje 4 karte svakom igracu
	for (int i = 0; i < igraci.size(); i++) {
		s.Podijeli4Karte(&igraci[i]);
	}
	
	// Pregled ostatka spila nakon dijeljenja
	cout << "\nPreostale karte u spilu (52):" << endl;
	for (int i = 0; i < s.karte.size(); i++) {

		cout << s.karte[i] << "\t";
		if (i > 0 && i % 10 == 0) cout << "\n";
	}
}
