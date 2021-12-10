#include <iostream>
#include "Operations.h"
using namespace Banque;
int Operation::compteur = 1;
Banque::Operation::Operation(Date* d, Devise* montant ) : num(compteur++)
{
	this->d = d;
	this->montant = montant;
	

}

void Banque::Operation::afficher()
{
	this->d->afficher();
	cout << " | num : " << this->num << " || " ;
	this->montant->afficher();
}
