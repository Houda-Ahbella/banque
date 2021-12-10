#include "ComptePayant.h"

double Banque::ComptePayant::coutop = 0.05;

Banque::ComptePayant::ComptePayant(Client* c, Devise* m) : Compte(c, m)
{
}

bool Banque::ComptePayant::debiter(Devise* M)
{
	Devise* res = NULL;
	if(M->type_devise()=='M')res = new MAD(1 + ComptePayant::coutop);
	if(M->type_devise()=='D')  res = new Euro(1 + ComptePayant::coutop);
	if(M->type_devise()=='E')  res = new Dollar(1 + ComptePayant::coutop);
	if(res)
	{ 
		res->operator*(M);
		return Compte::debiter(res);
	}
	else
	{
		return false;
	}
	

	
}

void Banque::ComptePayant::crediter(Devise* M)
{
	Devise* res = NULL;
	if (M->type_devise() == 'M')res = new MAD(1 - ComptePayant::coutop);
	if (M->type_devise() == 'D')  res = new Euro(1 - ComptePayant::coutop);
	if (M->type_devise() == 'E')  res = new Dollar(1 - ComptePayant::coutop);
	if (res)
	{
		res->operator*(M);
	 Compte::crediter(res);
	}
	
}

void Banque::ComptePayant::consulter() const
{
	cout << "le compte Payant:\n";
	this->Compte::consulter();

}