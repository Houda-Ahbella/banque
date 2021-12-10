#include "CompteCourant.h"

Banque::CompteCourant::CompteCourant(Client* c, Devise* m, Devise* dec)
	: Compte(c, m)
{
	this->decouvert = dec;
}

void Banque::CompteCourant::crediter(Devise* M)
{
	this->Compte::crediter(M);
}

bool Banque::CompteCourant::debiter(Devise* M)
{
	

	if (this->checkSolde(M, this->decouvert))
		return this->Compte::debiter(M);
	return false;
}

void Banque::CompteCourant::consulter() const
{
	cout << "le compte Courant:\n";
	this->Compte::consulter();
}