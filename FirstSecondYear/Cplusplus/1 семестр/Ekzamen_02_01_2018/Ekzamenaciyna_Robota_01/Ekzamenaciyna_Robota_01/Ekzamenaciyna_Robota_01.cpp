#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

struct Point{
	char name;
	int x, y, z;
	float vidst_0;
	float vid_t[5];
	float poz[2];
};


int main(){
	ifstream input;
	input.open("open.txt");
	const int n = 5;
	Point G[n];
	
	for (int i = 0; i < 5; i++) {
		input >> G[i].name;
		input >> G[i].x;
		input >> G[i].y;
		input >> G[i].z;
	}
	////
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			G[i].vid_t[j] = sqrt((G[i].x - G[j].x)* (G[i].x - G[j].x) + (G[i].y - G[j].y)* (G[i].y - G[j].y) + (G[i].z - G[j].z)* (G[i].z - G[j].z));
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4-i; j++) {
			if (G[j].vid_t[i] > G[j + 1].vid_t[i]) {
				Point tmp = G[j];
				G[j] = G[j + 1];
				G[j + 1] = tmp;
			}
		}
	}
	cout << "2 point z nayb vidst: " << endl;
	cout << G[4].name << ", " << G[3].name << ": " << G[4].vid_t[4] << endl;
	////
	for (int i = 0; i < 5; i++) {
		G[i].vidst_0 = sqrt(G[i].x * G[i].x + G[i].y * G[i].y + G[i].z *  G[i].z);
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4 - i; j++) {
			if (G[j].vidst_0 > G[j + 1].vidst_0) {
				Point tmp = G[j];
				G[j] = G[j + 1];
				G[j + 1] = tmp;
			}
		}
	}
	////
	cout << "vidstan vid centry:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << G[i].name << ": " << G[i].vidst_0 << endl;
	}

	system("pause");
    return 0;
}

