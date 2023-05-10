/*
Zadatak: https://i.imgur.com/YokcvuY.png
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Zivotinja {
public:
	string ime;
	double pTezina;

	Zivotinja(string _ime, double _pTezina) {
		ime = _ime;
		pTezina = _pTezina;
	}

	virtual void GetLokacija() {
		cout << "ZOO" << endl;
	}

	virtual ~Zivotinja() {
		cout << "Destruktor ZIVOTINJA" << endl;
	}
};

class Pas : public Zivotinja {
public:
	Pas(string ime) : Zivotinja(ime, 10) {}

	void GetLokacija() override {
		cout << "ZOO - dvoriste" << endl;
	}

	~Pas() {
		cout << "Destruktor PAS" << endl;
	}
};

class Riba : public Zivotinja {
public:
	string vrsta;

	Riba(string ime) : Zivotinja(ime, 3.5) {}

	void GetLokacija() override{
		cout << "ZOO - bazen" << endl;
	}

	~Riba() {
		cout << "Destruktor RIBA" << endl;
	}
};

class Sarun : public Zivotinja, public Riba {
public:
	Sarun(string ime) : Zivotinja(ime, 3), Riba(ime) {}
	~Sarun() {
		cout << "Destruktor SARUN" << endl;
	}
};

double ProsjecnaTezina(vector<Zivotinja*> zoo) {
	double pT = 0;

	for (int i = 0; i < zoo.size(); i++) {
		pT += zoo[i]->pTezina;
	}

	pT = pT / zoo.size();

	return pT;
}

int main() {
	
	Pas Rex("Rexic");
	Riba Nemo("Nemo");

	// c) //
	Rex.GetLokacija();
	Nemo.GetLokacija();

	// d) //
	Pas Mile("Mile");
	Riba Dora("Dora");
	Sarun Sare("Sare");

	vector <Zivotinja*> zoloski;

	zoloski.push_back(&Mile);
	zoloski.push_back(&Dora);
	zoloski.push_back(&Sare);

	cout << ProsjecnaTezina(zoloski) << endl;

	// e) //
	Zivotinja* z = new Pas("Rex");
	delete z;
}
