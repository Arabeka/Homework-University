#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	int q = 1;

	do {
		int  n, m;

		do {
			cout << "Enter n: ";
			cin >> n;
		} while (n < 2);
		do {
			cout << "Enter m: ";
			cin >> m;
		} while (m < 2);

		int **a = new int *[n];

		int Z;
		cout << "Zapovnutu Randomno? (1 or 0): ";
		do {
			cin >> Z;
		} while(Z < 0 || Z > 1);

		for (int i = 0; i < n; i++) {
			a[i] = new int[m];
			for (int j = 0; j < m; j++) {
				if (Z == 0) {
					cin >> a[i][j];
				}
				if (Z == 1) {
					a[i][j] = -9 + rand() % 19;
				}
			}
		}
		cout << "\nmatrix: \n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << setw(3) << a[i][j] << " ";
			}
			cout << endl;
		}
		// 1)
		int S = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (a[j][i] == 0) { 
					S += 1;
					break;
				}
			}
		}
		//2)
		int **b = new int*[n];
		for (int i = 0; i < n; i++) {
			b[i] = new int [2];
		}
		

		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (a[i][j] % 2 == 0 && a[i][j] > 0) {
					sum = sum + a[i][j];
				}
			}
			b[i][0] = sum;
			b[i][1] = i;
		}
		
		int **c = new int*[n];
		for (int i = 0; i < n; i++) {
			c[i] = new int[m];
		}
		//сортування характеристики
		for (int j = 0; j < n - 1; j++) {
			for (int i = 0; i < n - 1 - j; i++) {
				if (b[i][0] > b[i + 1][0]) { 
					int tmp0 = b[i][0];
					int tmp1 = b[i][1];
					//
					b[i][0] = b[i + 1][0];
					b[i][1] = b[i + 1][1];
					//
					b[i + 1][0] = tmp0;
					b[i + 1][1] = tmp1;
				}
			}
		}
		//
		cout << "\n\n";

		for (int i = 0; i < n; i++) {
			c[i] = new int[m];
			for (int j = 0; j < m; j++) {
				c[i][j] = a[b[i][1]][j];
				}
			}
		//вивід результатів
		cout << "\nRezyltatu: :" << endl;
		cout << "1) " << m - S << endl;
		cout << "2) ";
			/* << "Haracterustuka: \n";
		for (int i = 0; i < n; i++) {
			cout << b[i][0] << " ";
		}
		cout << "\n";
		for (int i = 0; i < n; i++) {
			cout << b[i][1] << " ";
		}
		*/
		cout << "matrix++: " << endl;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << setw(3) << c[i][j] << " ";
			}
			cout << endl;
		}

		cout << "\npress 1 or 0 to exed: ";
		cin >> q;

	} while (q == 1);

	return 0;
}