#include "stdafx.h"
#include <iostream>
using namespace std;

int main(){
	int m, n, NSD = 1;
	cout << "m: ";
	cin >> m;
	cout << "n: ";
	cin >> n;

	int k = 2;
	while ((m>0 && n>0) && (k < n || k < m)){
		if ((m%k == 0) && (n%k == 0)) {
				m = m / k;
				n = n / k;
				NSD *= k;
		}
		else k++;
	}
	cout << "NSD: " << NSD <<endl;
	system("pause");
    return 0;
}