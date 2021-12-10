#include "Client.h"
#include"Compte.h"
using namespace Banque;
using namespace std;
Banque::Client::Client(string n, string p, string a)
{
	this->ref = new GC(1);
	this->nom = n;
	this->prenom = p;
	this->adresse = a;
	this->list_compte = vector<Compte*>();
}

void Banque::Client::Afficher() const
{
	cout << "nom :" << this->nom << "-----" << "prenom:" << this->prenom << "-----" << "Adresse:" << this->adresse << endl;
	cout << "les comptes :" << endl;

	for (int i = 0; i < this->list_compte.size(); i++)
	{
		this->list_compte[i]->consulter();
	}
}

void Banque::Client::addCompte(Compte* c)
{
	this->ref->incre();
	this->list_compte.push_back(c);
}
