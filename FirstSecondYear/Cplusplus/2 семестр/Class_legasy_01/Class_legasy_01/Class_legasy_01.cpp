#include "stdafx.h"
#include <iostream>
#include "Kolo.h"
#include "Rectangle.h"
#include "Trapeze.h"
using namespace std;

int main(){
	const int n = 3;

	//cout << sqrt((2 - 3 + 4 + 6)*(3 - 2 + 4 - 6)*(3 - 2 - 4 + 6));

	Kolo Olena;
	 Olena >> cin;
	 Olena << cout;

	 Rectangle Rostik;
	 Rostik >> cin;
	 Rostik << cout;

	 Trapeze Denus;
	 Denus >> cin;
	 Denus << cout;

	 //Figura* obj[n];
	 //obj[0] = new Kolo;
	 //obj[2] = new Rectangle;
	 //obj[3] = new Trapeze;

	 system("pause");
    return 0;
}

