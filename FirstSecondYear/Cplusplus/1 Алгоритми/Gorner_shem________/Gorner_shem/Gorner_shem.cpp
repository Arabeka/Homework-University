#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

void gorner(int*a, int n, int x) {
	int p = a[0];
	p = p * x + a[1];

	for (int i = 0; i < n-2; i++) cout << "(";
	cout  << p;
	int count = 0;
	for (int i = 1; i<n - 1; i++) {
		p = p * x + a[i + 1];
		count++;
		if (a[i + 1] <= 0) {
			cout << "*" << x << "" << a[i + 1] << ")";
		}
		else cout << "*" << x << " + " << a[i + 1] << ")";
	}
	cout << " = " << p;
	cout << "\nMnojen: " << count<< endl;
}
void proste(int*a, int n, int x) {
	int count = 0, rez=a[n];

	for (int i = 0; i < n; i++) {
		rez += a[i] * pow(x, n - i);
		count +=  n-i;
	}
	cout << "rez prost mn: " << rez << endl;
	cout << "Mnojen: " << count << endl;


}


int main() {
	int n;
	cout << "n = ";
	cin >> n;
	int* a = new int [n];
	for (int i = n; i >= 0; i--) {
		cout << " a[" << n - i << "] = ";
		cin >> a[i];
	}
	int x;
	cout << "x = ";
	cin >> x;

	gorner(a, n + 1, x);
	cout << "\n/////////////////////////////\n";
	proste(a, n, x);
	system("pause");
	return 0;
}
