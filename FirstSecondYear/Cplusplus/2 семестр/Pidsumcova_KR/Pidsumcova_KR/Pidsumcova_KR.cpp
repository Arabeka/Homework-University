#include "stdafx.h"
#include "Skin.h"
#include "neSkin.h"

int main()
{
	double a0, q;
	int n;
	cout << "Enter: \na0: ";
	cin >> a0;
	cout << "q: "; cin >> q;
	cout << "n: "; cin >> n;

	Skin A(a0, q, n);
	A.sum();

	neSkin B(a0, q);
	B.sum();

	system("pause");
    return 0;
}

