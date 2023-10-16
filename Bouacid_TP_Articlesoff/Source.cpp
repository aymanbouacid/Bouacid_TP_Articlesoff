#include <iostream>
#include "Article.h"
#include "IHM.h"
#include <vector>
#include <Windows.h>

using namespace std;


int main()
{
	SetConsoleOutputCP(1252);
	//
	cout << "Utilisation des classes en C++ :" << endl;
	Gestion gest;
	IHM logiciel;
	logiciel.Start(&gest);
	//
	return 0;
}