#include "Gestion.h"
#include <fstream>

using namespace std;

Gestion::Gestion()
{
	ListArticle = new vector<Article*>();
	lireFichier();
}

Gestion::~Gestion()
{
	sauvegarderFichier();

	while (ListArticle->size() > 0)
	{
		Article* article = ListArticle->at(ListArticle->size() - 1);
		//
		delete article;
		ListArticle->pop_back();
	}

	// On libere la memoire du Vector
	delete ListArticle;
}
void Gestion::sauvegarderFichier()
{
	ofstream sortie = ofstream();
	sortie.open("../articles.txt");
	for (int i = 0; i < ListArticle->size(); i++)
	{
		Article* article = ListArticle->at(i);
		sortie << article->getNom() << " " << article->prixHT << " " << article->stock << endl;
	}
	sortie.close();
}


int Gestion::getTaille()
{
	return (int)ListArticle->size();
}


Article* Gestion::Ajouter(string nomArticle)
{
	Article* atemp = new Article(nomArticle);
	ListArticle->push_back(atemp);
	return atemp;
}

Article* Gestion::LireAt(int pos)
{
	Article* atemp = NULL;
	if ((pos >= 0) && (pos < getTaille()))
	{
		atemp = ListArticle->at(pos);
	}
	return atemp;
}


void Gestion::lireFichier()
{
	ifstream entree = ifstream();
	entree.open("../article.txt");
	if (!entree.fail())
	{
		Article* article;
		do
		{
			string tempNom;

			entree >> tempNom;
			article = new Article(tempNom);

			if (entree.eof())
			{
				delete article;
				break;
			}
			entree >> article->prixHT;
			entree >> article->stock;
			ListArticle->push_back(article);
		} while (!entree.eof());
		entree.close();
	}
}

bool Gestion::Supprimer(int pos)
{
	bool ok = false;
	if ((pos >= 0) && (pos < getTaille()))
	{
		Article* article = ListArticle->at(ListArticle->size() - 1);
		delete article;
		ListArticle->pop_back();
		ok = true;
	}
	return ok;
}


