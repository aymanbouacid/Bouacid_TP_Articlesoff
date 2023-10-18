#include "IHM.h"
#include <iostream>
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
	Article* temp;
	int index = 1;
	do
	{
		choix = AfficheMenu();

		switch (choix)
		{
		case 1:
			cout << "Entrez le nom de votre article :" << endl;
			cin >> nomArticle;
			temp = gestion->Ajouter(nomArticle);
			Modifier(temp);
			break;
		case 2:
			numArticle = this->ChoixArticle();
			if (numArticle > 0)
			{
				temp = gestion->LireAt(numArticle - 1);
				Modifier(temp);
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
				temp = gestion->LireAt(numArticle - 1);
				Afficher(temp);
			}
			break;
		case 5:
			AfficherTout();
			break;
		case 6:
			int nombreArticle;
			while (index != 0)
			{
				AfficherTout();
				cout << "Entrez un article que vous voulez acheter : (Tapez 0 pour sortir)" << endl;
				cin >> index;
				nombreArticle = 0;
				
				if ((index != 0) && (index <= gestion->getTaille()))
				{
					cout << "Entrez le nombre d'articles que vous voulez acheter " << endl;
					cin >> nombreArticle;
					if (nombreArticle <= gestion->LireAt(index - 1)->stock)
					{
						ModifierStock(gestion->LireAt(index - 1), nombreArticle);
						Article* article = new Article(gestion->LireAt(index - 1)->getNom());
						article->prixHT = gestion->LireAt(index - 1)->prixHT;
						article->stock = nombreArticle;
						achatdArticle->push_back(article);
					}
					else
					{
						cout << "Erreur : Pas de stock disponible, veuillez réessayer plus tard";
					}
					AfficherTicket();
				}
			}
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


//

int IHM::ChoixArticle()
{
	int numArticle = -1;
	if (gestion->getTaille() > 0)
	{
		cout << "Quel Article ? (1/" << gestion->getTaille() << ") :"<<endl;
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
	// On affiche tous les objets crees
	for (int j = 0; j < gestion->getTaille(); j++)
	{
		Article* article = gestion->LireAt(j);
		cout << article->getNom() << " - " << article->prixHT << " €" << " - " << article->stock << endl;
	}
}

void IHM::ModifierStock(Article* article, int nombreArticle)
{
	article->stock = article->stock - nombreArticle;
}

void IHM::AfficherTicket()
{
	cout << "********** Ticket **********" << endl;
	cout << left << "Nom" << right << "PrixHT" << right << "Stock" << endl;
	double totalHT = 0;
	double totalTTC;

	for (int i = 0; i < this->achatdArticle->size(); i++)
	{
		cout << i + 1 << " " << left << achatdArticle->at(i)->getNom() << right << achatdArticle->at(i)->prixHT << right << achatdArticle->at(i)->stock << endl;
		totalHT = totalHT + ((achatdArticle->at(i)->prixHT) * achatdArticle->at(i)->stock);
	}
	totalTTC = totalHT + (0.2 * totalHT);// 0.2 = 20%
	cout << "TotalHT :" << totalHT << endl;
	cout << "TotalTTC :" << totalTTC << endl;
}



