/*
Potrebno je napisati program za evidenciju igrača u ekipi. Ekipa se sastoji od igrača, a za svakog igrača se evidentira broj na dresu, 
ime, prezime i trzisna cijena. Potrebno je omogućiti ispis svih igrača u ekipi (naziv ekipe, te popis svih igrača poredano po broju na dresu). 
Također, potrebno je omogućiti jednostavno dohvaćanje informacija u ukupnoj cijeni svih igrača, najskupljem igraču, te prosječnoj cijeni svih igrača. 
Slijedeći programski odsječak u nastavku napišite sve potrebne klase i metode kojima se dobije očekivano ponašanje programskog koda.

int main(){

       Ekipa ekipa;
       ekipa.naziv = "Tim raketa";
       
       Igrac i1("Luka", "Modric");
       i1.broj = 10;
       i1.cijena = 50000000;
       ekipa.dodajIgraca(i1);

       Igrac i2("Mario", "Mandzukic");
       i2.broj = 9;
       i2.cijena = 27000000;
       ekipa.dodajIgraca(i2);

       Igrac i3("Darijo", "Srna");
       i3.broj = 11;
       i3.cijena = 14500000;
       ekipa.dodajIgraca(i3);
       
       ekipa.ispisi();
       
       Igrac najskuplji = ekipa.dohvatiNajskupljeg();
       cout << "Najskuplji igrac: ";
       najskuplji.ispisi();
       
       cout << "Ukupna cijena svih igraca: " << ekipa.ukupnaCijena() << endl;
       cout << "Prosjecna cijena jednog igraca: " << ekipa.prosjecnaCijena() << endl;

}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

class Igrac {
public:
    int broj;
    string ime_prezime;
    int cijena;

    Igrac(string ime, string prezime) {
        ime_prezime = ime + " " + prezime;
    }
    
    void ispisi() {
        cout << ime_prezime << endl;
    }

};

bool usporedba(Igrac a, Igrac b) {
    return a.cijena < b.cijena;
}

class Ekipa {
public:
    string naziv;
    vector<Igrac> igraci;
    
    void dodajIgraca(Igrac i) {
        igraci.push_back(i);
    }

    Igrac dohvatiNajskupljeg() {
        return *max_element(igraci.begin(), igraci.end(), usporedba);
    }

    void ispisi() {
        for (int i = 0; i < igraci.size(); i++) {
            cout << igraci[i].broj << ". - " << igraci[i].ime_prezime << "\tCijena: " << igraci[i].cijena << endl;
        }
    }

    double ukupnaCijena() {

        double sum = 0;
        
        for (int i = 0; i < igraci.size(); i++) {
            sum += (double)igraci[i].cijena;
        }

        return sum;
    }

    double prosjecnaCijena() {

        double avg = 0;

        avg = double(ukupnaCijena()) / double(igraci.size());

        return avg;
    }
};

int main() {

    Ekipa ekipa;

    ekipa.naziv = "Tim raketa";
    
    Igrac i1("Luka", "Modric");
    i1.broj = 10;
    i1.cijena = 50000000;
    ekipa.dodajIgraca(i1);

    Igrac i2("Mario", "Mandzukic");
    i2.broj = 9;
    i2.cijena = 27000000;
    ekipa.dodajIgraca(i2);

    Igrac i3("Darijo", "Srna");
    i3.broj = 11;
    i3.cijena = 14500000;
    ekipa.dodajIgraca(i3);

    ekipa.ispisi();

    Igrac najskuplji = ekipa.dohvatiNajskupljeg();

    cout << "Najskuplji igrac: ";

    najskuplji.ispisi();

    cout.precision(2);
    cout << fixed;
    cout << "Ukupna cijena svih igraca: " << ekipa.ukupnaCijena() << endl;
    cout << "Prosjecna cijena jednog igraca: " << ekipa.prosjecnaCijena() << endl;

    return 0;
}
