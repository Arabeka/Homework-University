#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "EmtiClass.h"

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
	cin >> n;
	


	EmtiClass<char> A  (getArr<char>(n), n);
	
	A.quickSort();




	system("pause");
    return 0;
}

