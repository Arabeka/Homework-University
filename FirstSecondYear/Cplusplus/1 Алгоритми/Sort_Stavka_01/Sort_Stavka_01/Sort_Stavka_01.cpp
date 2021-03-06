#include "stdafx.h"
#include <iostream>

using namespace std;

//int*  insertionSort(int *arrayPtr, int length){
//	int temp, item; 
//	int counter_por = 0;
//	for (int i = 1; i < length; i++){
//		counter_por++;
//		temp = arrayPtr[i]; 
//		item = i - 1; 
//		while (item >= 0 && arrayPtr[item] > temp) 
//		{
//			counter_por++;
//			arrayPtr[item + 1] = arrayPtr[item]; 
//			arrayPtr[item] = temp;
//			item--;
//		}
//	}
//	cout << "Porivniani: " << counter_por << endl;
//	return arrayPtr;
//}

int* insertionSort(int* arr, int n){
	int key;
	int left;
	int right;
	int mid;
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			key = arr[i];
			left = 0;
			right = i - 1;

			do {
				mid = (left + right) / 2;
				if (arr[mid] < key)     left = mid + 1;
				else	right = mid - 1;
			} while (left <= right);

			for (int j = i - 1; j >= left; j--)	{
				arr[j + 1] = arr[j];
			}
			arr[left] = key;
		}
	}
	return arr;
}

int main(){
	int n;
	cout << "Enter n: ";
	cin >> n;

	int* A = new int[n];
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 100;
		cout << A[i] << " ";
	}
	cout << endl;
	int* B = insertionSort(A, n);

	for (int i = 0; i < n; i++) {
		cout << B[i] << " ";
	}

	cout << endl;
	system("pause");
    return 0;
}

