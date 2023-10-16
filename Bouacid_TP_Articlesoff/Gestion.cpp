#include "Gestion.h"
#include <fstream>

using namespace std;

Gestion::Gestion() // Constructeur
{
	listArticle = new vector<Article*>();
	lireFichier();
}


Gestion::~Gestion() // Destructeur
{
	sauverFichier();
	// On libere tous les objets crees
	while (listArticle->size() > 0)
	{
		Article* article = listArticle->at(listArticle->size() - 1);
		//
		delete article;
		listArticle->pop_back();
	}

	// On libere la memoire du Vector
	delete listArticle;
}
void Gestion::sauverFichier()
{
	ofstream sortie = ofstream();
	sortie.open("../Bouacid_TP_Articlesoff/article.txt");
	for (int i = 0; i < listArticle->size(); i++)
	{
		Article* article = listArticle->at(i);
		sortie << article->getNom() << " " << article->prixHT << " " << article->stock << endl;
	}
	sortie.close();
}


int Gestion::getTaille()
{
	return (int)listArticle->size();
}


Article* Gestion::Ajouter(string nomArticle)
{
	Article* temp = new Article(nomArticle);
	listArticle->push_back(temp);
	return temp;
}

Article* Gestion::LireAt(int pos)
{
	Article* temp = NULL;
	if ((pos >= 0) && (pos < getTaille()))
	{
		temp = listArticle->at(pos);
	}
	return temp;
}


void Gestion::lireFichier()
{
	ifstream entree = ifstream();
	entree.open("../Bouacid_TP_Articlesoff/article.txt");
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
			listArticle->push_back(article);
		} while (!entree.eof());
		entree.close();
	}
}

bool Gestion::Supprimer(int pos)
{
	bool ok = false;
	if ((pos >= 0) && (pos < getTaille()))
	{
		Article* article = listArticle->at(listArticle->size() - 1);
		delete article;
		listArticle->pop_back();
		ok = true;
	}
	return ok;
}
