#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int** getMatrix(int n) {
	int **matr = new int *[n];
	for (int i = 0; i < n; i++) {
		matr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			matr[i][j] = -90 + rand() % 190;
		}
	}
	return matr;
	delete[]matr;
}

int main(){
	int n;
	cout << "Enter n: ";
	cin >> n;

	int** matr = getMatrix(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << matr[i][j] << " ";
		}
		cout << endl;
	}

	int  poz_max = 0, max = matr[0][0];
	int  poz_min = 0, min = matr[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matr[i][j] > 0) {
				max = matr[i][j];
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matr[i][j] < max && matr[i][j] > 0) {
				max = matr[i][j];
				poz_max = i;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matr[i][j] > min && matr[i][j] < 0) {
				min = matr[i][j];
				poz_min = i;
			}
		}
	}
	cout << "max: " << max << " " << poz_max+1 << endl;
	cout << "min: " << min << " " << poz_min + 1 << endl;

	int *sum = new int[n];

	for (int i = 0; i < n; i++) {
		sum[i] = matr[poz_max][i] + matr[poz_min][i];
	}
	cout << "sum: ";
	for (int i = 0; i < n; i++) {
		cout << sum[i] << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}