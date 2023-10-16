#pragma once
#include "Article.h"
#include <vector>

using namespace std;

class Gestion
{

	vector<Article*>* ListArticle;
	void lireFichier();
	void sauvegarderFichier();

public:
	Gestion();
	~Gestion();

	int getTaille();

	Article* Ajouter(string nomArticle);
	Article* LireAt(int pos);
	bool Supprimer(int pos);

};