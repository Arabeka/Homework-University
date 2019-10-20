#include "stdafx.h"
#include <iostream>
#include "Light.h"
#include "Heavi.h"

using namespace std;

int main()
{
	int n;
	cout << "Enter K-ct machin: "; cin >> n;

	Auto** A = new Auto*[n];

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			A[i] = new Light();
		}
		else {
			A[i] = new Heavi();
		}
	}

	for (int i = 0; i < n; i++) {
		cout << "\nMachin N" << i + 1 << endl;
		*A[i] >> cin;
	}


	cout << "\n Info for machine:\n";
	for (int i = 0; i < n; i++) {
		cout << "\nMachin N" << i + 1 << endl;
		A[i]->pring_inf();
	}

	system("pause");
    return 0;
}

