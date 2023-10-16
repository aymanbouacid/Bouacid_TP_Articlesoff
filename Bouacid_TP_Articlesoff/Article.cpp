#include "Article.h"
#include <string>


using namespace std;



Article::Article(string n)
{
	this->nom = n;
}

string Article::getNom()
{
	return this->nom;
}
