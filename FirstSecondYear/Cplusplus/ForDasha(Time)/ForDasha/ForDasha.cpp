#include "pch.h"
#include <iostream>
#include "Time.h"

int main()
{
	Time t1;

	t1 >> cin;
	(t1 + t1) << cout;
	cout << endl;
	(t1 - t1) << cout;
	cout << endl;

    system("pause");
}

