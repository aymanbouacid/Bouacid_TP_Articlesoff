#include <iostream>
#include "Article.h"
#include "IHM.h"
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1252);
	//
	cout << "Utilisation des classes en C++ :" << endl;
	Gestion gestion;
	IHM logiciel;
	logiciel.Start(&gestion);
	//
	return 0;
}