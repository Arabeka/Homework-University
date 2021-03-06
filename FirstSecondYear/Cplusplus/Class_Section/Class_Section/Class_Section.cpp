#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Lines_Collection.h"

using namespace std;

int main()
{
	ifstream in("inFile.txt");
	ofstream out("outFile.txt");

	Lines_Collection Collection(in);
	Collection.readSection(in);
	Collection.readLamana(in);

	Collection.printToFile(out);

	
	Collection.removeSection(1);
	Collection.addLamana(2, 3, 4, 1, 5, 2);

	Collection.printToFile(out);

	Collection.removeLamana(2);

	Collection.printToFile(out);

	system("pause");
    return 0;
}

