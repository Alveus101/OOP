#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> izdvoji(vector<int>& brojevi, function<bool(int)> kriterij) {

    vector<int> izdvojeni;

    for (int i = 0; i < brojevi.size(); i++) {
        if (kriterij(brojevi[i])) {
            izdvojeni.push_back(brojevi[i]);
        }
    }

    return izdvojeni;
    
}

int main() {
    vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };
    vector<int> rez = izdvoji(brojevi, [](int broj) { return !(broj % 3); });

    for (int i = 0; i < rez.size(); i++) {
        cout << rez[i] << " ";
        // ispis: 3 6 12 87 66 3 72 42
    }

}
