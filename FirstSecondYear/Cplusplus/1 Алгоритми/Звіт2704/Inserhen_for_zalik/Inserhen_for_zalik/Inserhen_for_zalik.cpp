#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

int* insertion_sort(int* mas,  int n)
{
	int C = 0, M = 0;
	double time1 = clock();
	int key = 0, j = 0;
	for (int i = 1; i < n; i++)
	{
		
		key = mas[i];
		j = i - 1;
		while (j >= 0 && mas[j] > key)
		{
			C+=2;
			mas[j + 1] = mas[j];
			j--;
			M++;
		}
		mas[j + 1] = key;
		//M += 3;
	}
	double time2 = clock();

	cout << "C: " << C << endl;
	cout << "M: " << M << endl;
	//cout << "time: " << time2    <<" "<< time1 <<" "<<   double(time2 - time1) / double(CLOCKS_PER_SEC) << endl;
	return mas;
}

int* Rev_insertion_sort(int* mas, int n)
{
	int C = 0, M = 0;
	int time = clock();
	int key = 0, j = 0;
	for (int i = 1; i < n; i++)
	{

		key = mas[i];
		j = i - 1;
		while (j >= 0 && mas[j] < key)
		{
			C += 2;
			mas[j + 1] = mas[j];
			j--;
			M++;
		}
		mas[j + 1] = key;
		M += 3;
	}
	time = clock() - time;

	cout << "C: " << C << endl;
	cout << "M: " << M << endl;
	//cout << "time: " << time << " " << " " << double(time) / (CLOCKS_PER_SEC) << endl;
	return mas;
}

int main()
{
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << endl;
	/*arr = Rev_insertion_sort(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;*/
	long time1 = clock();
	cout << time1 << endl;
	arr = insertion_sort(arr, n);

	long time2 = clock();
	cout << time2 << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	system("pause");
    return 0;
}

