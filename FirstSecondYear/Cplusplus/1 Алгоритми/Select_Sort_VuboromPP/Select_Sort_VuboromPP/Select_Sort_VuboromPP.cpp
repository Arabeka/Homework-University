#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Sort(int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << endl;
	int count = 0;
	for (int i = 0; i < n/2; i++) {     //зовнішній цикл
		int min = i;
		int max = i;
		for (int j = i + 1; j < n -1 - i; j++) {    //внутрішній цикл
		/*	if (arr[j] < arr[min]) {
				min = j;
				max = n - j - 1;
				count++;
			}
			if (arr[n-j-1] > arr[max]) {
				max = n-j-1;
				count++;
			}*/
			count += 3;
			if (arr[j] < arr[j + 1]) {
				if (arr[min] > arr[j]) min = j;
				if (arr[max] < arr[j + 1]) max = j+1;
			}
			else {
				if (arr[min] > arr[j + 1]) min = j+1;
				if (arr[max] < arr[j]) max = j;
			}
		}
		if (i == max) {
			swap(arr[i], arr[min]);
			max = min;
			swap(arr[n - i - 1], arr[max]);
		}
		else {
			swap(arr[i], arr[min]);
			swap(arr[n - i - 1], arr[max]);
		}
		for (int c = 0; c < n; c++) {
			cout << arr[c] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout <<"\nCount: " << count << endl;
}

int main(){
	int n;
	cout << "Enter n: "; 
	cin >> n;
	Sort(n);
	
	system("pause");
    return 0;
}