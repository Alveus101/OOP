/*
Zadatak: https://i.imgur.com/iepULPj.png
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

    class Knjiga {
    public:
        string naziv;
        int kolicina;
        static int brojac;

        Knjiga() {};
        Knjiga(string _naziv, int _kolicina) {
            naziv = _naziv;
            kolicina = _kolicina;
            if (kolicina > 10) {
                brojac++;
            }


        }

        static void getPopularnaKnjiga() {
            cout << "Knjiga sa vise od 10 primjeraka ima:" << brojac << endl;
        }
    };
    int Knjiga::brojac = 0;

    namespace Knjiznica {
        class Polica {
      
        public:
            vector<Knjiga>policaKnjiga;

            template<class... T>
            Polica(T... argumenti) : policaKnjiga({ argumenti... }) {}

            Polica(initializer_list<Knjiga> argumenti) : policaKnjiga({ argumenti }) {}

           /* Polica operator -(Knjiga _knjiga) {

                for (int i = 0; i < policaKnjiga.size(); i++) {
                    if (policaKnjiga[i].naziv == _knjiga.naziv) {
                        policaKnjiga.erase(policaKnjiga.begin() + i);
                        cout << _knjiga.naziv << " je maknuta sa police." << endl;
                    }
                }
                return policaKnjiga;
            }*/

            virtual string getZanr() {
                return "zanr";
            }
        };
       
    }

    Knjiznica::Polica operator -(Knjiznica::Polica _polica,Knjiga _knjiga) {

        for (int i = 0; i < _polica.policaKnjiga.size(); i++) {
            if (_polica.policaKnjiga[i].naziv == _knjiga.naziv) {
                _polica.policaKnjiga.erase(_polica.policaKnjiga.begin() + i);
                cout << _knjiga.naziv << " je maknuta sa police." << endl;
            }
        }
        return _polica;
    }

    class Drama : public Knjiznica:: Polica{
    public:
        template<class... T>
        Drama(T... argumenti) : Polica({ argumenti... }) {}

        Drama(initializer_list<Knjiga> argumenti) : Polica({ argumenti }) {}

        string getZanr() override{
            return "Drama";
        }

    };
    class Akcija : public Knjiznica::Polica {
    public:
        template<class... T>
        Akcija(T... argumenti) : Polica({ argumenti... }) {}

        Akcija(initializer_list<Knjiga> argumenti) : Polica({ argumenti }) {}
        string getZanr() override{
            return "Akcija";
        }

    };
    
    bool usporediKnjige(Knjiga a, Knjiga b) {
        if (a.kolicina == b.kolicina) {
            return a.naziv[0] < b.naziv[0];

        }
        else
        return a.kolicina < b.kolicina;
    }
  
    class Manji{
    public:
        bool operator()(Knjiga a, Knjiga b) {
            if (a.kolicina == b.kolicina) {
                return a.naziv[0] < b.naziv[0];

            }
            else
                return a.kolicina < b.kolicina;
        }
    };

    class Korisnik {
    public:
        Knjiznica::Polica* polica;
        Korisnik() {};
        

        Korisnik(Korisnik&& privremeni) {
            this->polica = privremeni.polica;
            privremeni.polica = NULL;
            

        }

        Korisnik& operator =(Korisnik&& privremeni) {
            delete polica;
            this->polica = privremeni.polica;
            privremeni.polica = NULL;
            return *this;
        }

        Korisnik(const Korisnik& privremeni) {
            polica = new Knjiznica::Polica(*(privremeni.polica));
       
        }

        Korisnik& operator = (const Korisnik& privremeni) {
            // dealociraj sve postojeće pokazivače u vektoru
            if (this != &privremeni) {
                delete polica;
                polica = new Knjiznica::Polica(*(privremeni.polica));
            }
            return *this;
        }

       //  Destructor
        ~Korisnik() {
            polica = nullptr;
            delete polica;
        }
    };

int main()
{
    Knjiga Crvenkapica("Crvenkapica", 12);
    Knjiga RatIMir("RatIMir", 3);
    Knjiga Metamorfoza(" Metamorfoza", 23),Vlak("Vlak",33), Avion("Avion", 24);
   

    Knjiga::getPopularnaKnjiga();

    Knjiznica::Polica Polica1(Crvenkapica, RatIMir, Metamorfoza);
    Knjiznica::Polica Polica2{ Crvenkapica, RatIMir, Vlak, Avion};
    Knjiznica::Polica Polica3{ Crvenkapica, RatIMir, Vlak, Avion };

    cout << "Broj razlicitih knjiga na prvoj polici:" << Polica1.policaKnjiga.size() << endl;
    cout << "Broj razlicitih knjiga na drugoj polici:" << Polica2.policaKnjiga.size() << endl;

    Polica1 = Polica1 - Crvenkapica;
    
    Akcija Polica4;
    Knjiznica::Polica* pAkcija = &Polica4;
    cout << pAkcija->getZanr() << endl;

    Drama Polica5;
    Knjiznica::Polica* pDrama = &Polica5;
    cout << pDrama->getZanr() << endl;


    sort(Polica2.policaKnjiga.begin(), Polica2.policaKnjiga.end(), usporediKnjige);

    sort(Polica2.policaKnjiga.begin(), Polica2.policaKnjiga.end(), Manji());

    sort(Polica2.policaKnjiga.begin(), Polica2.policaKnjiga.end(), [](Knjiga& a, Knjiga& b) { 

        if (a.kolicina == b.kolicina) {
            return a.naziv[0] < b.naziv[0];

        }
        else
            return a.kolicina < b.kolicina;

        });

    for (int i = 0; i < Polica2.policaKnjiga.size(); i++) {
        cout << Polica2.policaKnjiga[i].naziv << " " << Polica2.policaKnjiga[i].kolicina << endl;
    }

    Korisnik k1;
    k1.polica = &Polica2;
    
    Korisnik k2 = move(k1);
   
    Korisnik k3;
    k3 = k2;
    cout << k3.polica->policaKnjiga[0].naziv << endl;

    Korisnik k4(k2);
    cout << k4.polica->policaKnjiga[0].naziv << endl;
  
    k4 = Korisnik();
}
