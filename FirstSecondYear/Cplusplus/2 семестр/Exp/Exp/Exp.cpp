// Exp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Perevid.h"
using namespace std;

template <class T>

T* getArr(int n) {
	T* arr = new T[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	return arr;
}

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;

	Perevid<long> A(getArr<long>(n), n);

	system("pause");
    return 0;
}

