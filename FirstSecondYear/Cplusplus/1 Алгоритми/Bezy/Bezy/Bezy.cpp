#include "stdafx.h"
#include <iostream>
#include  <cmath>
using namespace std;

int revers(long n) {
	long rez = n%10;
	while (n > 9) {
		rez *= 10 ;
		n /= 10;
		rez += n % 10;
	}
	return rez;
}
int main(){
	long n;
	cout << "Enter n: "; 
	cin >> n;
	while (n != revers(n)) {
		n += revers(n);
	}
	cout << n << endl; 
	system("pause");
    return 0;
}