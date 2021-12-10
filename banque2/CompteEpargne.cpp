#include <assert.h>
#include "CompteEpargne.h"
#include "Devise.h"

Banque::CompteEpargne::CompteEpargne(Client* c, Devise* m, double TI) : Compte(c, m)
{
	assert(TI > 0 && TI <= 100);
	this->tauxI = TI;
}

void Banque::CompteEpargne::calculInteret()
{
	 MAD* a = new MAD(this->tauxI / 100);
	 this->Compte::crediter(&this->pourcetage(a));
}

void Banque::CompteEpargne::consulter() const
{
	cout << "le compte Epargne:\n";
	this->Compte::consulter();

}