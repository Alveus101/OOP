/*
Napišite predložak funkcije "NeparniElementi" koja prima vektor podataka bilo kojeg tipa, a vraća samo neparne elemente tog vektora.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <class T>
auto NeparniElementi(vector<T>& v) {

	vector<T> neparni;

	for (int i = 0; i < v.size(); i++) {
		if ( v[i] % 2 != 0)
			neparni.push_back(v[i]);
	}

	return neparni;
}


int main() {

	vector<int> vec = { 1, 2, 3, 4, 5, 6 };
	vector<int> rez = NeparniElementi(vec);

	for (int i = 0; i < rez.size(); i++)
		cout << rez[i] << " ";

}
