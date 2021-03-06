#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Batia.h"
#include "Child.h"
#include <iomanip>

using namespace std;

const int n = 5;

int main()
{
#pragma region creation_Humans

	Human** A = new Human*[n];

	for (int i = 0; i < n; i++) {
		if (i == 0 || i == 1) A[i] = new Batia();
		else A[i] = new Child();
	}

#pragma endregion 
	//створення масиву людей
	//перші 2 - об'єкти класу Batia
	//решта 3 - об'єкти класу Child

#pragma region file_input
	ifstream infile("infile.txt");
	string name, skin; int age, zybu, zp, cm; bool home;
	for (int i = 0; i < 2; i++) {
		//A[i]->set_all(infile);
		infile >> name;
		A[i]->set_name(name); //set
		infile >> age;
		A[i]->set_age(age);   //set
		infile >> skin;
		A[i]->set_skin(skin); //set
		infile >> zp;
		A[i]->set_zp(zp);     //set
		infile >> cm;
		A[i]->set_cm(cm);     //set
	}
	for (int i = 2; i < n; i++) {
		infile >> name;
		A[i]->set_name(name); //set
		infile >> age;
		A[i]->set_age(age);   //set
		infile >> skin;
		A[i]->set_skin(skin); //set
		infile >> zybu;
		A[i]->set_zp(zybu);   //set
		infile >> home;
		A[i]->set_cm(home);   //set
	}
	infile.close();
#pragma endregion    
	//Цикл зчитує інфу з файлу і заносить її в масив людей

#pragma region Childs_output_in_file
	ofstream fileForChild("deddom.txt");
	int child_counter = 0;
	fileForChild << "Діти: \n";

	for (int i = 2; i < n; i++) {
		fileForChild << A[i]->get_name() << "\n";
		child_counter++;
	}
	fileForChild << "\nКількість дітей: " << child_counter;

	fileForChild.close();
#pragma endregion 
	//метод для виведення дітей в файл

#pragma region Batia_output_in file

	for (int i = 0; i < 2 - 1; i++) {
		if (A[i]->get_cm() > A[i+1]->get_cm())
			swap(A[i], A[i + 1]);
	}

	ofstream fileForBatia("file2.txt");

	for (int i = 0; i < 2; i++) {
		fileForBatia << A[i]->get_name() << ":\n";
		fileForBatia << "Вік: " << A[i]->get_age() << "\n";
		fileForBatia << "Особлива прикмета: " << A[i]->get_skin() << "\n";
		fileForBatia << "Зарплата: " << A[i]->get_zp() << " руппі\n";
		fileForBatia << "Ріст: " << A[i]->get_cm() << "\n\n";
	}
	fileForBatia.close();

#pragma endregion
	//сортування батьків та вивід їх у файл

	return 0;
}