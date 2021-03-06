#include "stdafx.h"
#include <iostream>
using namespace std;
class Excep {};

class NegativeNum : public Excep {
public:
	int a;
	NegativeNum() {}
	NegativeNum(int a) {
		this->a = a;
	}
	void Message()
	{
		cout << "Negative namber!\n";
	}
};

class DivideByZiro : public Excep {
public:
	int a;
	DivideByZiro() {}
	DivideByZiro(int a) {
		this->a = a;
	}
	void Message()
	{
		cout << "Devived by zero!\n";
	}
};

void harmony(int a, int b) {
	try {
		if (a == 0 || b == 0) {
			throw DivideByZiro(a);
		}
		if (a < 0 || b < 0) {
			throw NegativeNum(a);
		}
		cout << 2 / (1.0 / a + 1.0 / b);
	}
	catch (DivideByZiro a) {
		a.Message();
	}
	catch (NegativeNum a) {
		a.Message();
	}
}

int main() {
	int a, b;

	cout << "   2  " << endl;
	cout << "-------" << endl;
	cout << "1    1" << endl;
	cout << "-- + --" << endl;
	cout << "a    b" << endl;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "Rez: ";
	harmony(a, b);
	cout << endl;
	system("pause");
	return 0;
}
