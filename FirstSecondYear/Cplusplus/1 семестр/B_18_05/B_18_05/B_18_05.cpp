#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;

int main() {
	string s;
	cout << "Enter line: " << endl;
	getline(cin, s);

	string S = s + " q";
	int count = 0;

	int left = 0;
	int right;
	
	for (int i = 0; i<S.length() ; i++) {
		if (S[i] == ' ' /*&& S[i + 1] != ' '*/) {
			right = i;
	//		cout << S.substr(left, right - left) << endl;
		//	cout << left << "  " << right << "\n";
			int b_count = 0;
			for (int j = left; j<right; j++) {
				if (S[j] == 'b') {
					b_count += 1;	
				}
			}
			if (b_count == 3) {
				count++;
			//	cout << " govno\n";
			//	cout << "B_count: " << b_count << endl;
			}
			left = right;
		}
	}
	cout << "\nCount: " << count << endl;
	system ("pause");
	return 0;
}