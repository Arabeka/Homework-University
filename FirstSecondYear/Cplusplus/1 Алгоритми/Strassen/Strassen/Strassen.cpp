#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int** criateMatr(int n, int m) {
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) arr[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = rand() % 2;

	return arr;
}
void printMatr(int** Matr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(3) << Matr[i][j] << " ";
		}
		cout << endl;
	}
}
int** normalizeMatr(int** Matr, int maxSize, int n, int m) {
	int **c = new int *[maxSize];
	for (int i = 0; i < maxSize; i++) {
		c[i] = new int[maxSize];
		for (int j = 0; j < maxSize; j++)
		{
			if (i < n && j < m) c[i][j] = Matr[i][j];
			else c[i][j] = 0;
		}
	}
	return c;
}
int** sumMatr(int** A, int** B, int size) {
	int** C = new int*[size];
	for (int i = 0; i < size; i++) {
		C[i] = new int[size];
		for (int j = 0; j < size; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}
int** riznMatr(int**A, int** B, int size) {
	int**C = new int*[size];
	for (int i = 0; i < size; i++) {
		C[i] = new int[size];
		for (int j = 0; j < size; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	return C;
}
int** Strassen(int** A, int** B, int size) {
	int** C = new int*[size];

	/*створення підматриць*/
	int **A1 = new int *[size / 2];
	int **A2 = new int *[size / 2];
	int **A3 = new int *[size / 2];
	int **A4 = new int *[size / 2];
	int **B1 = new int *[size / 2];
	int **B2 = new int *[size / 2];
	int **B3 = new int *[size / 2];
	int **B4 = new int *[size / 2];
	for (int i = 0; i < size / 2; i++) {
		A1[i] = new int[size / 2];
		A2[i] = new int[size / 2];
		A3[i] = new int[size / 2];
		A4[i] = new int[size / 2];
		B1[i] = new int[size / 2];
		B2[i] = new int[size / 2];
		B3[i] = new int[size / 2];
		B4[i] = new int[size / 2];
	}
	/*/////////////////////*/
	/*заповнення підматриць*/
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i < size / 2) {
				if (j < size / 2) {                     //  ( A1 0 )   ( B1 0 )
					A1[i][j] = A[i][j];                 //  ( 0  0 )   ( 0  0 )
					B1[i][j] = B[i][j];
				}
				else {
					A2[i][j - size / 2] = A[i][j];      //  ( 0  A2)   ( 0  B2)
					B2[i][j - size / 2] = B[i][j];      //  ( 0  0 )   ( 0  0 )
				}
			}
			else {
				if (j < size / 2) {
					A3[i - size / 2][j] = A[i][j];      //  ( 0  0 )   ( 0  0 )
					B3[i - size / 2][j] = B[i][j];      //  ( A3 0 )   ( B3 0 )
				}
				else {
					A4[i - size / 2][j - size / 2] = A[i][j];   //  ( 0  0 )   ( 0  0 )
					B4[i - size / 2][j - size / 2] = B[i][j];   //  ( 0  A4)   ( 0  B4)
				}
			}
		}
	}
	/*////////////////////*/

	if (size > 2) {
		int **M1 = Strassen(sumMatr(A1, A4, size / 2), sumMatr(B1, B4, size / 2), size / 2);
		int **M2 = Strassen(sumMatr(A3, A4, size / 2), B1, size / 2);
		int **M3 = Strassen(A1, riznMatr(B2, B4, size / 2), size / 2);
		int **M4 = Strassen(A4, riznMatr(B3, B1, size / 2), size / 2);
		int **M5 = Strassen(sumMatr(A1, A2, size / 2), B4, size / 2);
		int **M6 = Strassen(riznMatr(A3, A1, size / 2), sumMatr(B1, B2, size / 2), size / 2);
		int **M7 = Strassen(riznMatr(A2, A4, size / 2), sumMatr(B3, B4, size / 2), size / 2);

		for (int i = 0; i < size; i++) {
			C[i] = new int[size];
			for (int j = 0; j < size; j++) {
				if (i < size / 2) {
					if (j < size / 2) {
						C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];            //C1
					}
					else {
						C[i][j] = M3[i][j - size / 2] + M5[i][j - size / 2];             //C2
					}
				}
				else {
					if (j < size / 2) {
						C[i][j] = M2[i - size / 2][j] + M4[i - size / 2][j];             //C3
					}
					else {
						C[i][j] = M1[i - size / 2][j - size / 2] - M2[i - size / 2][j - size / 2]
							+ M3[i - size / 2][j - size / 2] + M6[i - size / 2][j - size / 2];       //C4
					}
				}
			}
		}
	}
	else {
		int m1 = (A1[0][0] + A4[0][0]) * (B1[0][0] + B4[0][0]);
		int m2 = (A3[0][0] + A4[0][0]) * B1[0][0];
		int m3 = A1[0][0] * (B2[0][0] - B4[0][0]);
		int m4 = A4[0][0] * (B3[0][0] - B1[0][0]);
		int m5 = (A1[0][0] + A2[0][0]) * B4[0][0];
		int m6 = (A3[0][0] - A1[0][0]) * (B1[0][0] + B2[0][0]);
		int m7 = (A2[0][0] - A4[0][0]) * (B3[0][0] + B4[0][0]);

		for (int i = 0; i < size; i++) {
			C[i] = new int[size];
			for (int j = 0; j < size; j++) {
				if (i < size / 2) {
					if (j < size / 2) {
						C[i][j] = m1 + m4 - m5 + m7;
					}
					else {
						C[i][j] = m3 + m5;
					}
				}
				else {
					if (j < size / 2) {
						C[i][j] = m2 + m4;
					}
					else {
						C[i][j] = m1 + m3 - m2 + m6;
					}
				}
			}
		}
	}
	return C;
}

int main()
{
	int n_A, m_A, n_B, m_B;

	do {
		cout << "Enter rozmir of matrix A(n,m): ";
		cin >> n_A >> m_A;
	} while (n_A < 1 || m_A < 1);
	do {
	cout << "Enter rozmir of matrix B(n,m): ";
	cin >> n_B >> m_B;
	} while (n_B < 1 || m_B < 1);

	int** A = criateMatr(n_A, m_A);
	int** B = criateMatr(n_B, m_B);

	/*пошук потрібної розмірності*/
	int maxSize = (int)fmax(fmax(n_A, n_B), fmax(m_A, m_B));
	maxSize = (int)pow(2, ceil(log(maxSize) / log(2)));
	/*///////////////////////////*/

	/*зведення матриць до розміру 2^n*/
	A = normalizeMatr(A, maxSize, n_A, m_A);
	B = normalizeMatr(B, maxSize, n_B, m_B);
	/*///////////////////////////////*/


	cout << "\nMatrix A:" << endl;
	printMatr(A, maxSize, maxSize);
	cout << "\nMatrix B:" << endl;
	printMatr(B, maxSize, maxSize);

	
	int** C = Strassen(A, B, maxSize);
	cout << "\nMatrix C:" << endl;
	printMatr(C, maxSize, maxSize);

	cout << endl;
	system("pause");
	return 0;
}
