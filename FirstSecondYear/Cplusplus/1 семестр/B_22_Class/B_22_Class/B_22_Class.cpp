#include "stdafx.h"
#include "Triangle.h"
#include <iostream>
using namespace std;

int main() {
	int q;
	do {
		Triangle Gov;
		Gov.getCoord();
		Gov.stvorennia();
		Gov.isnye();
		Gov.peremist();
		Gov.zmina_rozm();
		Gov.povorot();
		cout << "exet? (1 or 0): ";
		cin >> q;
	} while (q == 0);

    return 0;
}

