// Sort_vuborom_plys.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int const n = 6;
	int a[n] = { 5, -3, 4, 2 , 1, -2 };

	for (int i = 0; i <= n - 2; i++) {
		int min = i; 
		//max = i;
	
		for (int j = i + 1; j <= n - 1; j++) {
			if (a[j] < a[min])
				min = j;
		}
		swap(a[i], a[min]);
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	system("pause");
    return 0;
}

