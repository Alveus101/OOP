/*
Napišite lambda funkciju za zamjenu dvije varijable.
*/

#include <iostream>

using namespace std;

int main() {
	int a = 10, b = 9;

	//lamda
	[](int& broj1, int& broj2) { int temp = broj1; broj1 = broj2; broj2 = temp; }(a, b);

	cout << a << " " << b << endl; // 9 10
}
