/*
Zadatak: https://i.imgur.com/BpTkeRe.png
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Element {
public:
	string naziv;
	int obujam;
	static int VeciOdTri;

	Element(string n, int o) {
		naziv = n;
		obujam = o;

		if (obujam > 3) {
			VeciOdTri++;
		}
	}

	// a) 
	static int getVelikiELementi() {
		return VeciOdTri;
	}
};

namespace Zgrada {
	class Stan {
	public:

		vector<Element> elementi;

		// b)
		template <class ...T>
		Stan(T... args) : elementi({ args... }) {}

		// c)
		Stan(initializer_list<Element> args) : elementi({ args }) {}

		// e)
		virtual string getVrsta() {
			return "N/A";
		}
	};
}

// a)
int Element::VeciOdTri = 0;

// d)
Zgrada::Stan operator + (Zgrada::Stan a, Zgrada::Stan b) {

	Zgrada::Stan rezultat;

	for (int i = 0; i < a.elementi.size(); i++) {
		rezultat.elementi.push_back(a.elementi[i]);
	}

	for (int i = 0; i < b.elementi.size(); i++) {
		rezultat.elementi.push_back(b.elementi[i]);
	}

	return rezultat;
}

// e)

class Apartman : public Zgrada::Stan{
public:
	string getVrsta() override {
		return "Apartman";
	}
};

class Garsonijera : public Zgrada::Stan {
public:
	string getVrsta() override {
		return "Garsonijera";
	}
};

// f)
bool usporediElemente(Element a, Element b) {

	if (a.obujam == b.obujam) {

		int size = a.naziv.size();
		if (a.naziv.size() > b.naziv.size())
			size = a.naziv.size();
		else
			size = b.naziv.size();

		for (int i = 0; i < size; i++) {
			if (a.naziv[i] != b.naziv[i])
				return a.naziv[i] < b.naziv[i];
		}
	}

	else return a.obujam < b.obujam;
}

// f)
class usporedba {
public:
	bool operator()(Element a, Element b) {

		if (a.obujam == b.obujam) {

			int size = a.naziv.size();
			if (a.naziv.size() > b.naziv.size())
				size = a.naziv.size();
			else
				size = b.naziv.size();

			for (int i = 0; i < size; i++) {
				if (a.naziv[i] != b.naziv[i])
					return a.naziv[i] < b.naziv[i];
			}
		}
		
		else return a.obujam < b.obujam;
	}
};

// g)
class Vlasnik {
public:
	Zgrada::Stan* pokazivac;

	Vlasnik(){}
	Vlasnik(const Vlasnik& v) {
		pokazivac = new Zgrada::Stan(*(v.pokazivac));
	}

	Vlasnik& operator = (const Vlasnik& privremeni) {
		if (this != &privremeni) {
			delete pokazivac;
			pokazivac = new Zgrada::Stan(*(privremeni.pokazivac));
		}

		return *this;
	}

	~Vlasnik() {
		pokazivac = nullptr;
		delete pokazivac;
	}
};

int main() {
	Element e1("Drugi", 1), e2("Prvi", 1), e3("Treci", 3);

	// b)
	Zgrada::Stan s1(e1, e2, e3);

	// c)
	Zgrada::Stan s2{ e1, e2, e3 };

	// d)
	Zgrada::Stan s3 = s1 + s2;
	
	for (int i = 0; i < s3.elementi.size(); i++) {
		cout << s3.elementi[i].naziv << s3.elementi[i].obujam << endl;
	}

	// e)
	Apartman s4;
	cout << s4.getVrsta() << endl;

	Garsonijera s5;
	cout << s5.getVrsta() << endl;

	// f)
	Zgrada::Stan s6(e3, e1, e2);

	// a.
	//sort(s6.elementi.begin(), s6.elementi.end(), usporediElemente);

	// b.
	//sort(s6.elementi.begin(), s6.elementi.end(), usporedba());

	// c.
	sort(s6.elementi.begin(), s6.elementi.end(), [](Element a, Element b) { 

		if (a.obujam == b.obujam) {

			int size = a.naziv.size();
			if (a.naziv.size() > b.naziv.size())
				size = a.naziv.size();
			else
				size = b.naziv.size();

			for (int i = 0; i < size; i++) {
				if (a.naziv[i] != b.naziv[i])
					return a.naziv[i] < b.naziv[i];
			}
		}

		else return a.obujam < b.obujam; 
		
	});

	// Provjera za f)
	for (int i = 0; i < s6.elementi.size(); i++) {
		cout << s6.elementi[i].naziv << " " << s6.elementi[i].obujam << endl;
	}

	// g)
	Vlasnik v1;
	v1.pokazivac = &s1;

	Vlasnik v2(v1);
	
	cout << v2.pokazivac->elementi[0].naziv << endl;

	Vlasnik v3 = v1;

	cout << v3.pokazivac->elementi[0].naziv << endl;
}
