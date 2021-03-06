#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

int* CountingSort(int* arr, int n, int min, int max)
{

	int *c = new int[max + 1 - min]; // 7
	for (int i = 0; i < max + 1 - min; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		c[arr[i] - min] = c[arr[i] - min] + 1;
	}
	int i = 0;
	for (int j = min; j < max + 1; j++) {
		while (c[j - min] != 0) {
			arr[i] = j;
			c[j - min]--;
			i++;
		}
	}
	return arr;
}

int main()
{
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		arr[i] = (rand() % 200) - 100;
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	int max = arr[0], min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}

	double time1 = clock();
	arr = CountingSort(arr, n, min, max);
	double time2 = clock();


	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

//	cout << "\ntime: " << time2 << " " << time1 << " " << double(time2 - time1) / double(CLOCKS_PER_SEC) << endl;

	cout << endl;
	system("pause");
	return 0;
}

