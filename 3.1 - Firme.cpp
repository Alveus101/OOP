#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Zaposlenik {
public:

	string ime;
	string prezime;
	int placa;

	Zaposlenik() {
		cout << "Zaposlenik constructor called" << endl;
	}

	~Zaposlenik() {
		cout << "Zaposlenik destructor called" << endl;
	}

	void setIme(string _ime) {
		ime = _ime;
	}

	void setPrezime(string _prezime) {
		prezime = _prezime;
	}

	void setPlaca(int _placa) {
		placa = _placa;
	}
};



class Firma {

	string naziv;
	string oib;
	string adresa;
	vector <Zaposlenik> zaposlenici;

public:

	void setNaziv(string _naziv) {

		if (_naziv.length() < 5) {
			cout << "Ime firme je prekratko!" << endl;
		}
		else naziv = _naziv;
	};

	void setOib(string _oib) {
		while (_oib.length() != 13) {
			cout << "OIB nema 13 znamenki!" << endl;
			cout << "Unesi OIB : ";
			cin >> _oib;
		}
		oib = _oib;
	}

	void setAdresa(string _adresa) {
		adresa = _adresa;
	}

	void dodajZaposlenika1(Zaposlenik z) {
		zaposlenici.push_back(z);
	}

	void dodajZaposlenika2(Zaposlenik& z) {
		zaposlenici.push_back(z);
	}

	void dodajZaposlenika3(Zaposlenik* z) {
		zaposlenici.push_back(*z);
	}

	void ispisSvihZaposlenika() {
		for (int i = 0; i < zaposlenici.size(); i++) {
			cout << i << ". " << zaposlenici[i].ime << " " << zaposlenici[i].prezime << " " << zaposlenici[i].placa << endl;
		}
	}

	Zaposlenik nadjiZaposlenika1(string ime, string prezime) {
		zaposlenici[0].ime = ime;
		zaposlenici[0].prezime = prezime;
	}

	Zaposlenik* nadjiZaposlenika2(string ime, string prezime) {
		zaposlenici[1].ime = ime;
		zaposlenici[1].prezime = prezime;
	}

	Zaposlenik& nadjiZaposlenika3(string ime, string prezime) {
		zaposlenici[2].ime = ime;
		zaposlenici[2].prezime = prezime;
	}
};



int main() {

	string naziv, oib, adresa;
	Firma f; Zaposlenik z;
	Zaposlenik* pZ = &z;
	
	cout << "Unesi naziv firme: ";
	cin.ignore();
	getline(cin, naziv);

	f.setNaziv(naziv);

	cout << "Unesi OIB : ";
	cin >> oib;

	f.setOib(oib);

	cout << "Unesi adresu firme: ";
	cin.ignore();
	getline(cin, adresa);

	f.setAdresa(adresa);

	z.setIme("Zdravko");
	z.setPrezime("Mamic");
	z.setPlaca(1000000);

	//f.dodajZaposlenika1(z);
	//f.dodajZaposlenika2(z);
	f.dodajZaposlenika3(pZ);

	f.ispisSvihZaposlenika();
}
