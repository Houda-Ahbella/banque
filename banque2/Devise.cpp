#include "Devise.h"
#include  <iostream>
using namespace std;
using namespace Banque;
Devise::Devise(double val)
{
	this->valeur = val;
}

Banque::Devise::Devise(Devise& D)
{
	this->valeur = D.valeur;
}

void Banque::Devise::operator+(const Devise& M)
{
	this->valeur = this->valeur + M.valeur;
}


void Banque::Devise::operator-(const Devise& M)
{
	double m = this->valeur - M.valeur;
	if(m>=0) this->valeur = m;
	else {
		cout << "le montant a debiter est suprieur au solde du compte\n";
	}
}

void Banque::Devise::operator*(Devise* M)
{
	this->valeur = this->valeur * M->valeur;
}




bool Devise::operator<=(const Devise& M) const
{
	return this->valeur <= M.valeur;
}

bool Devise::operator>=(const Devise& M) const
{
	return this->valeur >= M.valeur;
}



void Devise::afficher() const
{
	cout << "le solde est : " << this->valeur;
}

