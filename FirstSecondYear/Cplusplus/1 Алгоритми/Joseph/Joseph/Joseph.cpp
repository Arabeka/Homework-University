#include "stdafx.h"
#include <iostream>

using namespace std;

int joseph(int n, int k) {
	int res = 0;
	for (int i = 1; i <= n; ++i)
		res = (res + k) % i;
	return res + 1;
}

int main()
{
	int n, k=2;
	cout << "Enter the number of people: ";
	cin >> n;
	/*cout << "Enter the killing step: ";
	cin >> k;*/

	cout << "Live remains: " << joseph(n, k) << endl;

	system("pause");
    return 0;
}

