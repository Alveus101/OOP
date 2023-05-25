/*
Napišite predložak klase Red koji ima mogućnost dodavanja novog elementa na kraju reda metodom Dodaj, te uklanjanja zadnjeg elementa u redu metodom Brisi.
Navedena klasa također mora imati podatkovni član BrojElemenata koji vraća trenutni broj elemenata u redu.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <class T>
class Red {
public:
    int BrojElemenata = 0;
	vector<T> red;
	Red(int b);

	void Dodaj( T item ) {
		red.push_back(item);
		BrojElemenata++;
	}
	void Brisi() {
		red.pop_back();
		BrojElemenata--;
	}
};

template <class T>Red<T> :: Red(int b){
	BrojElemenata = b;
}

int main() {
	int a = 1, b = 3, c = 2;
	Red<int> r(3);

	r.Dodaj(a);
	r.Dodaj(c);
	r.Dodaj(b);

	for (int i = 0; i < r.red.size(); i++)
		cout << r.red[i] << " ";

	r.Brisi();

	cout << "\nBRISANJE..." << endl;

	for (int i = 0; i < r.red.size(); i++)
		cout << r.red[i] << " ";

}
