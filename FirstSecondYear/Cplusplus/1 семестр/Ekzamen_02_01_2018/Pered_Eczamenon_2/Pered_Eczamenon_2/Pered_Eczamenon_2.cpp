//Структура Клас. Імена і ріст учнів. вивести найбільшого і найменшого учня.
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;
struct Class {
	string name;
	int rist;
};

int main(){
	ifstream input;
	input.open("Gov.txt");
	int n=6;
//	input >> n;

	Class *arr = new Class[n];

	for (int i = 0; i < n; i++) {
		input >> arr[i].name;
		input >> arr[i].rist;
	}

	for (int j = 0; j < n - 1; j++) {
		for (int i = 0; i < n - 1 - j; i++) {
			if (arr[i].rist > arr[i + 1].rist) {
				swap(arr[i], arr[i + 1]);
			}
		}
	}

	cout << "Min: ";
	cout << arr[0].name << endl;

	cout << "Max: ";
	cout << arr[n - 1].name << endl;

	system("pause");
    return 0;
}

