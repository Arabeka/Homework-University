#include "stdafx.h"
#include "Animal.h"
#include <iostream>
#include "Machina.h"
#include "AnimalHeart.h"
#include "Heart.h"
using namespace std;

int main()
{

	//Animal A("monkey");
	//A.eat_fruct();

	//Machina A(false);


	Heart H(true);
	AnimalHeart A(H, true);


	cout << endl;
	system("pause");
	return 0;
}

