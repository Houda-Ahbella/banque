#include "Compte.h"
#include"OperationA.h"
#include"OperationR.h"
#include<iostream>
using namespace std;
using namespace Banque;
MAD* Compte::plafond = new MAD(2000);
int Compte::count = 0;
Banque::Compte::Compte(Client* titulaire, Devise* D) :numcompte(++count)
{
	
	this->titulaire = titulaire;
	this->solde = D;
	this->historique = vector<Operation*>();
}

void Banque::Compte::crediter(Devise* M  )
{
	Date* d = new Date();
	OperationA* op = new OperationA(d, M);
	this->historique.push_back(op);
	if (this->solde->type_devise() == 'M') M->convert('M');
	if (this->solde->type_devise() == 'D') M->convert('D');
	if (this->solde->type_devise() == 'E') M->convert('E');
	 *(this->solde) + *M;
	
}

bool Banque::Compte::debiter(Devise* M)
{
	if (this->solde->type_devise() == 'M') M->convert('M');
	if (this->solde->type_devise() == 'D') { M->convert('D');  Compte::plafond->convert('D'); }
	if (this->solde->type_devise() == 'E') { M->convert('E');   Compte::plafond->convert('E');}
	if (*(this->solde) >= *M && *M <= *(Compte::plafond))
	{
		 *(this->solde) - *M;

		Date* d = new Date();
		Operation* op = new OperationR(d, M);
		this->historique.push_back(op);
		return true;
	}
	return false;
}

Banque::Compte::Compte(const Compte& c) :numcompte(c.numcompte)
{
	
	this->titulaire = c.titulaire;
	this->solde = c.solde;
	this->historique = c.historique;

}

bool Banque::Compte::verser(Devise* M, Compte& C)
{
	if (this->debiter(M) == true) {
		C.crediter(M);
		return true;
	}
	return false;
}


void Banque::Compte::consulter() const
{
	cout << "num compte=" << this->numcompte << endl;
	this->solde->afficher();
	cout << "Historique des operations " << endl;
	//this->titulaire->Afficher();

	for (int i = 0; i < this->historique.size(); i++)
	{
		this->historique[i]->afficher();
	}
}



Compte::~Compte() {

	if (this->titulaire != nullptr && this->titulaire->ref->decr()==0)
	{
		if(this->titulaire)
		delete this->titulaire;
		this->titulaire = nullptr;
	}
}

bool Banque::Compte::checkSolde(Devise* M, Devise* dec)
{
	char type1, type2;
	type1 = this->solde->type_devise();
	M->convert(type1);
	
	this->solde->operator-(*M);

	if (*this->solde >= *dec)
	{
		this->solde->operator+(*M);
		return true;
   }
	this->solde->operator+(*M);

	return false;
}

Devise& Banque::Compte::pourcetage(Devise* a)
{
	//if (this->solde->type_devise() == 'M') a->convert('M');
	if (this->solde->type_devise() == 'D')  a->convert('D');  
	if (this->solde->type_devise() == 'E')  a->convert('E');   
	a->operator*(this->solde);
	return *a;
}

