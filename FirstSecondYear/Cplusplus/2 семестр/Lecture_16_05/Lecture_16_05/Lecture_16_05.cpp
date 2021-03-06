#include "stdafx.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void Out(int n) {
	cout << n << " ";
}

bool isMult7(int n) {
	return n % 7 == 0;
}

int main()
{
	vector<int> arr(15), A;

	for (int i = 0; i < arr.size(); i++) {
		arr[i] = 15 - i;
	}

	//for_each(arr.begin(), arr.end(), Out); //виконує функцію Out для всіх всіх елементів масиву

	find(arr.begin(), arr.end(), 5);             //знайти п'ятірку в масиві

	find_if(arr.begin(), arr.end(), isMult7);    // повертає перший ітератор з діапазону для якого виконується якась умова для якогось числа
												 // поверне 14
	

	//count();                       //кількість елементів з якимось значенні на проміжку
	//count_if();                //кількість елементів на проміжку що задовольняють якусь умову

	//equal();                    // чи два діапазони збігаються

	int initial[15] = { 1,2,3,5,5,6,1,2,3,4,6,3,4,5 };
	int patern[3] = { 4,5,6 };
	//int i;

	vector<int> first(initial, initial + 15);
	vector<int> second(patern, patern + 3);
	for (auto i : first) cout << i << " ";
	cout << endl;
	for (auto i : second) cout << i << " ";



	//search();                 // повертає ітератор шуканої підпослідовності яка виконує якусь умову.
							  // 




	cout << endl;
	system("pause");
    return 0;
}

