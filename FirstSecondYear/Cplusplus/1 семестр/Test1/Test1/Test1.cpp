#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string  n[2], x[2];
	int k = 2;
	cin >> n[0] >> n[1];
	cout << endl;
	cin >> x[0] >> x[1];

	for (int i = 0; i < 2; i++) {
		if (k != 3) {
			swap(n[i], x[i]);
		}
	}
	cout << n[0] <<" " << x[0] <<endl;
	cout << n[1] << " " << x[1] << endl;
	int q;
	cin >> q;
    return 0;
}

