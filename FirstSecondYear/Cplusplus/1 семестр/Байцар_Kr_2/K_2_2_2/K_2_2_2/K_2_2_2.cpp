#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	string S;
	cout << "Enter radok: \n";
	getline(cin, S);

	int wk1 = 0;
	int wk2;
	string Rez;
	for (int i = 0; i < S.size(); i++) {
		if ((S[i] == ',' || S[i] == '.') && S[i + 1] != ',') {
			wk2 = i;
			int b = 0;
			for (int j = wk1; j < wk2; j++) {
				if (S[j] == S[wk2-1]) {
					b++;
				}
				if (b == 2) {
					for (int k = wk1; k < wk2; k++) {
						Rez += S[k];
					}
					Rez += " ";
				}
			}
			wk1 = wk2;
		}
		else if (S[i] == '.') {
			break;
		}
	}


	cout << Rez;

	system("pause");
    return 0;
}

