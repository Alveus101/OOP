/*
ZADATAK:
Studenti i bodovi
Vektor, konstruktor, algoritmi
Potrebno je napisati program za praćenje bodovnog stanja studenata na određenom kolegiju. Slijedeći programski 
odsječak u nastavku napišite sve potrebne klase i metode kojima se dobije očekivano ponašanje programskog koda.

int main(){
vector<Bodovi> OOPBodovi{
		Bodovi(Student("Ivana Ivic", "0246002475"), 25),
		Bodovi(Student("Ivica Ivanovic", "0246005654"), 20),
		Bodovi(Student("Marko Markic", "0246004234"), 32)
};
Kolegij OOP("Objektno orijentirano programiranje", OOPBodovi);

//   Preko objekta OOP ispišite bodove svih studenata tog kolegija počevši od    
//   onih s najmanjim brojem bodova prema većim. Npr.;
	
//   Objektno orijentirano programiranje bodovi:
//   Ivica Ivanovic  0246005654      20
//   Ivana Ivic      0246002475      25
//   Marko Markic    0246004234      32

return 0;
}
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
	string ime;
	string jmbag;

	Student(string _ime, string _jmbag) : ime(_ime), jmbag(_jmbag) {}
};

class Bodovi {
public:
	int bodovi;
	Student student;

	Bodovi(Student s, int b) : student(s), bodovi(b) {}
};

class Kolegij {
public:
	string ime;
	vector<Bodovi> bodovi;

	Kolegij(string _ime, vector<Bodovi> _bodovi) : ime(_ime), bodovi(_bodovi) {}
};

bool Usporedba(Bodovi b1, Bodovi b2) {
	return b1.bodovi < b2.bodovi;
}

int main() {
	vector<Bodovi> OOPBodovi{
			Bodovi(Student("Ivana Ivic", "0246002475"), 25),
			Bodovi(Student("Ivica Ivanovic", "0246005654"), 20),
			Bodovi(Student("Marko Markic", "0246004234"), 32)
	};
	Kolegij OOP("Objektno orijentirano programiranje", OOPBodovi);

	/* Preko objekta OOP ispišite bodove svih studenata tog kolegija počevši od
	   onih s najmanjim brojem bodova prema većim. Npr.;

	   Objektno orijentirano programiranje bodovi:
	   Ivica Ivanovic  0246005654      20
	   Ivana Ivic      0246002475      25
	   Marko Markic    0246004234      32
	*/

	sort(OOP.bodovi.begin(), OOP.bodovi.end(), Usporedba);

	for (int i = 0; i < OOP.bodovi.size(); i++) {
		cout << OOP.bodovi[i].student.ime << "\t" << OOP.bodovi[i].student.jmbag << "\t" << OOP.bodovi[i].bodovi << endl;
	}

	return 0;
}
