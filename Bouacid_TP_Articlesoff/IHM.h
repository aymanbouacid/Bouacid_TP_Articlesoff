#pragma once
#include "Article.h"
#include <vector>
#include "Gestion.h"

using namespace std;


class IHM
{

	Gestion* gestion = NULL;

public:

	IHM();
	~IHM();

	void Start(Gestion* gestion);
private:
	int AfficheMenu();
	int ChoixArticle();
	void Modifier(Article*);
	void Afficher(Article*);
	void AfficherTout();

};