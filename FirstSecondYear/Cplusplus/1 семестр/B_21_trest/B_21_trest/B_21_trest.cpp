#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "stdafx.h"

using namespace std;

struct Student {
	string First_name;
	string Last_name;
	string Group;
	int points[5];
	float averege;
	bool good_only;
};

void Print_file(Student* people, int classes, ofstream& output) {
	for (int i = 0; i<classes; i++) {
		output << people[i].First_name <<" ";
		output << people[i].Last_name <<endl;
		output << people[i].Group <<endl;
		output << people[i].averege <<endl;
		output << endl;
		if (people[i].good_only == true) {
			cout << people[i].First_name <<endl;
			cout << people[i].Last_name <<endl;
			cout << people[i].Group <<endl;
			cout << endl;
		}
	}
}

void sortPeople(Student* people, int classes) {
	for (int i = 0; i<classes - 1; i++) {
		for (int j = 0; j<classes - 1 - i; j++) {
			if (people[j].averege>people[j + 1].averege) {
				Student tmp = people[j];
				people[j] = people[j + 1];
				people[j + 1] = tmp;
			}
		}
	}

}

void Get_file(Student* people, int classes, ifstream& input) {
	for (int i = 0; i < classes; i++) {
		cin >> people[i].First_name;
		cin >> people[i].Last_name;
		cin >> people[i].Group;
		for (int j = 0; j < 5; j++) {
			cin >> people[i].points[j];
			people[i].averege += people[i].points[j];
			if (people[i].points[j] >= 3) {
				people[i].good_only = true;
			}
			else people[i].good_only = false;
		}
		people[i].averege = people[i].averege / 5;

	}
} 
int main() {
	int classes;
	cin >> classes;
	auto ch = new float[classes];
	ifstream input;
	input.open("input");
	ofstream output;
	output.open("output");
	Student people[10];

	Get_file(people, classes, input);

	sortPeople(people, classes);

	Print_file(people, classes, output);
	return 0;
}