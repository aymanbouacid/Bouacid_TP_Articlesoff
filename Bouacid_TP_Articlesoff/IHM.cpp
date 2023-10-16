#include <iostream>
#include "IHM.h"
#include "Gestion.h"

using namespace std;

IHM::IHM()
{

}

IHM::~IHM()
{

}

void IHM::Start(Gestion* g)
{
	this->gestion = g;
	int choix;
	int numArticle;
	string nomArticle;
	Article* atemp;

	do
	{
		choix = AfficheMenu();

		switch (choix)
		{
		case1:
			cout << "Article : ";
			cin >> nomArticle;
			atemp = gestion->Ajouter(nomArticle);
			Modifier(atemp);
			break;
		case2:
			numArticle = this->ChoixArticle();

			if (numArticle > 0)
			{
				atemp = gestion->LireAt(numArticle - 1);
				Modifier(atemp);
			}
			break;
		case 3:
			numArticle = this->ChoixArticle();
			if (numArticle > 0)
			{
				gestion->Supprimer(numArticle - 1);
			}
			break;
		case 4:
			numArticle = this->ChoixArticle();
			if (numArticle > 0)
			{
				atemp = gestion->LireAt(numArticle - 1);
				Afficher(atemp);
			}
			break;
		case 5:
			AfficherTout();
			break;
		case 6:

			break;
		}
	} while (choix != 0);
}


int IHM::AfficheMenu()
{
	int choix;
	cout << "     **********  Menu  ********** " << endl;
	cout << "1 : Ajouter un Article" << endl;
	cout << "2 : Modifier un Article" << endl;
	cout << "3 : Supprimer un Article" << endl;
	cout << "4 : Afficher un Article" << endl;
	cout << "5 : Afficher les Articles hors stock" << endl;
	cout << "6 : Acheter des Articles" << endl;
	cout << "0 : Quitter" << endl;
	cout << "Entrez un choix" << endl;
	cout << "Choix :";
	cin >> choix;
	return choix;
}




int IHM::ChoixArticle()
{
	int numArticle = -1;
	if (gestion->getTaille() > 0)
	{
		cout << "Quel Article ? (1/" << gestion->getTaille() << ") :";
		cin >> numArticle;
		if (!((numArticle >= 1) && (numArticle <= gestion->getTaille())))
		{
			numArticle = -1;
		}
		// !!!!! Attention numEtudiant commence à 1 !!!!!
	}
	return numArticle;
}




void IHM::Modifier(Article* article)
{
	cout << "     **********  Modification  ********** " << endl;
	cout << "Article : " << endl << "Nom : ";
	cout << article->getNom() << endl;
	cout << "PrixHT : ";
	cin >> article->prixHT;
	cout << "Stock : ";
	cin >> article->stock;
	//
}


void IHM::Afficher(Article* article)
{
	cout << "     **********  Affichage  ********** " << endl;
	cout << article->getNom() << " - " << article->prixHT << " €" << " - " << article->stock << endl;
}


void IHM::AfficherTout()
{
	cout << "     **********  Affichage  ********** " << endl;
	// On affiche tous les objets crées
	for (int j = 0; j < gestion->getTaille(); j++)
	{
		Article* article = gestion->LireAt(j);
		cout << article->getNom() << " - " << article->prixHT << " €" << " - " << article->stock << endl;
	}
}
			
		


