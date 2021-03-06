#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int* binary(int n, int& count) {
	string s;
	while (n > 1) {
		s += (char(n % 2) + '0');
		n /= 2;
	}
	if (n != 0)
		s += (char(n) + '0');
	//cout << s << "\n";
	//cout << s << "\n";
	count = s.length();
	int*arr = new int[s.length()];
	for (int i = 0; i < count; i++) {
		arr[i] = s[i] - '0';
	//	cout << arr[i] << " ";
	}
	cout << "\n";
	return arr;
}

void leftToRight(int* b, int a, int n, int count)
{
	int p = a;
	int count1 = 0;
	int klkst = 0;
	for (int i = count; i >= 0; i--){
		p = p * p;
		if (b[i] == 1 && count1 == 1) p = a;
		if (b[i] == 1 && count1 != 1) p = p * a;
		count1++;
		klkst++;
	}
	cout << "Left to right: " << a << "^" << n << " = " << p << endl;
	cout << "K-ct` mnoj: " << klkst << endl;
}

void rightToLeft(int* b, int a, int n, int count) {
	long t = a;
	long p;
	int klkst = 0;
	if (b[0] == '1') p = a;
	else p = 1;
	for (int i = 1; i < count; i++) {
		t = t * t;
		klkst++;
		if (b[i] == 1) {
			p = t * p;
			klkst++;
		}
	}
	cout << "Right to left: " << a << "^" << n << " = " << p << endl;
	cout << "K-ct` mnoj: " << klkst << endl;
}
int main()
{
	int count = 0;
	int a;
	cout << "a: ";
	cin >> a;
	int n;
	cout << "^n: ";
	cin >> n;
	int*b = binary(n, count);
	cout << endl;

	leftToRight(b, a, n, count);
	rightToLeft(b, a, n, count);

	system("pause");
	return 0;
}


