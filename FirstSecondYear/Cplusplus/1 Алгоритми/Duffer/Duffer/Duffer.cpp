#include "stdafx.h"
#include <iostream>
#include <cmath>

double k = 3.0;
using namespace std;

int sum(int* arr, double _l, double _r) {
	int l = ceil(_l);
	int r = ceil(_r);
	int rez = 0;
	while (l < r) {
		rez += arr[l];
		l++;
	}
	return rez;
}

int check2(int *arr, int i, int n) {
	int batch1, batch2;

	if ((n - i) % 2 == 0) {
		batch1 = sum(arr, i, (n + i) / 2);
		batch2 = sum(arr, (n + i) / 2, n);

		if (batch1 == 0) return i;
		else if (batch2 == 0) return (n + i) / 2;

		if (batch1 < batch2) {
			i = i; n = (n + i) / 2;
		}
		else {
			i = (n + i) / 2; n = n;
		}
	}
	else {
		batch1 = sum(arr, i, (n + i) / 2);
		batch2 = sum(arr, ((n + i) / 2) + 1, n);

		if (batch1 < batch2) {
			i = i; n = (n + i) / 2;
		}
		else if (batch1 > batch2) {
			i = (n + i) / 2 + 1; n = n;
		}
		else {
			return (n + i) / 2;
		}

		if (batch1 == 0) return i;
		else if (batch2 == 0) return (n + i) / 2;
	}

	check2(arr, i, n);
}


int check3(int *arr, int i, int n) {
	int batch1, batch2, batch3;

	if (n % 3 == 1) {
		if (arr[n - 1] == 0) return n - 1;
		n = n - 1;
	}
	else if (n % 3 == 2) {
		if (arr[n - 1] == 0) return n - 1;
		else if (arr[n - 2] == 0) return n - 2;
		n = n - 2;
	}

	batch1 = sum(arr, i, (n / k) + i);
	batch2 = sum(arr, (n / k) + i, ((n / k) * 2) + i);
	batch3 = sum(arr, ((n / k) * 2) + i, n);

	/*cout << "batch1: " << batch1 << "      L: " << i << "   R: " << n / k + i << endl;
	cout << "batch2: " << batch2 << "      L: " << (n / k) + i << "   R: " << ((n / k) * 2.0) + i << endl;
	cout << "batch3: " << batch3 << "      L: " << ((n / k) * 2.0) + i << "   R: " << n << endl << endl;
*/
	if (batch1 == 0) return i;
	else if (batch2 == 0) return  ceil(n / k) + i;
	else if (batch3 == 0) return  ceil((n / k) * 2) + i;

	if (batch1 < batch2) {
		i = i; n = (n / k);
		//cout << "L: " << i << "   R: " << n << "   k: " << k << endl;
	}
	else if (batch2 < batch3) {
		i = (n / k); n = ((n / k) * 2);
		k *= 2;
	//	cout << "L: " << i << "   R: " << n << "   k: " << k << endl;
	}
	else if (batch3 < batch1) {
		i = ((n / k) * 2); n = n;
		k *= 2;
		//cout << "L: " << i << "   R: " << n << "   k: " << k << endl;
	}

	check2(arr, i, n);
}


int main()
{
	int n;
	do {
		cout << "Enter the number of coins: "; cin >> n;
	} while (n < 1);

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		arr[i] = 1;
	}

	arr[rand() % n] = 0;

	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Check2: " << check2(arr, 0, n) + 1 << " coin are fake!\n\n";
	cout << "Check3: " << check3(arr, 0, n) + 1 << " coin are fake!\n";

	system("pause");
	return 0;
}

