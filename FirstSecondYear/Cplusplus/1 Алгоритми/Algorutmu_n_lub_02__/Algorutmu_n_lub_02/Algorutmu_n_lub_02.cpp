#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int Cub_Symu(int n) {
	int rez = 0;
	while (n >= 1) {
		rez = n % 10 + rez;
		n /= 10;
	}
	return rez * rez*rez;
}
int main(){
	int n;
	cout << "Enter n: ";
	do { 
		cin >> n; 
	} while (n < 100);
	if (n*n == Cub_Symu(n)) cout << n * n << " = " << Cub_Symu(n) << ": true" << endl;
	else cout<< n * n << " = " << Cub_Symu(n) << ": folse" << endl;
	system("pause");
    return 0;
}

