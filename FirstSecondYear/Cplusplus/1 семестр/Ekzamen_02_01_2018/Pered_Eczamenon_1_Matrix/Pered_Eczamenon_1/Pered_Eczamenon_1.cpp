#include "stdafx.h"
#include <iostream>
#include <iomanip>  // setw()
using namespace std;
// задано матрицю. знайти max елемент серед min елементів тих рядків в яких  
// є від'ємний елемент на головній діагоналі
int** getMatrix(int n) {
	int **matr = new int *[n];
	for (int i = 0; i < n; i++) {
		matr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			matr[i][j] = -9 + rand() % 19;
		}
	}
	return matr;
	delete[]matr;
}

void print(int n, int** matr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(5) << matr[i][j] << "   ";
		}
		cout << endl;
	}
}

int main(){
	int n;
	cout << "n: ";
	cin >> n;

	int **matr = getMatrix(n);
	print(n, matr);
	int max;
	int *min = new int[n];

	for (int i = 0; i < n; i++) {
		min[i] = matr[i][i];
		if (matr[i][i] < 0) {
			for (int j = 0; j < n; j++) {
				if (matr[i][j] < matr[i][i]) {
					min[i] = matr[i][j];
				}
			}
		}
		cout << "| " << min[i] << " |";
	}

	max = min[0];
	for (int i = 0; i < n; i++) {
		if (min[i] > max && min[i] <0) {
			max = min[i];
		}
	}
	cout << "\nRez: " << max;

	int q;
	cin >> q;
	system("payse");
    return 0;
}

