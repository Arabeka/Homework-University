//Матриця. Найбільший елемент на початок, найменший на кінець рядка.
#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <string>
#include <fstream>
#include <conio.h>
#include  <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

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
	do {
		cout << "Enter: ";
		cin >> n;
	} while (n < 2);

	int **matr = getMatrix(n);

	print(n, matr);

	int **max = new int *[n];
	int **min = new int *[n];
	for (int i = 0; i < n; i++) {
		min[i] = new int[2];
		max[i] = new int[2];
	}
	////////////////////////////////////
	for (int i = 0; i < n; i++) {
		max[i][0] = matr[i][0];
		for (int j = 0; j < n; j++) {
			if (matr[i][j] > max[i][0]) {
				max[i][0] = matr[i][j];
				max[i][1] = j;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (matr[i][0] != max[i][0]) {
			int tmp = matr[i][0];
			matr[i][0] = max[i][0];
			matr[i][max[i][1]] = tmp;
		}
	}
	///////////////////////////////////////
	for (int i = 0; i < n; i++) {
		min[i][0] = matr[i][0];
		for (int j = 0; j < n; j++) {
			if (matr[i][j] < min[i][0]) {
				min[i][0] = matr[i][j];
				min[i][1] = j;
			}
		}
	}
	
	

	for (int i = 0; i < n; i++) {
		int tmp = matr[i][n-1];
		  matr[i][n-1] = min[i][0];
		matr[i][min[i][1]] = tmp;
		}

	cout << endl;
	print(n, matr);
	system("pause");
    return 0;
}

