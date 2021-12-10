#include "Dollar.h"
#include  <iostream>
using namespace std;
using namespace Banque;

Banque::Dollar::Dollar(double v) :Devise(v)
{
}

void Banque::Dollar::convert(char type)
{
	if (type == 'M')
	{
		this->Devise::operator*(new Dollar(9.26));
	}
	if (type == 'E')
	{
		this->Devise::operator*(new Dollar(0.88));
	}
}

void Banque::Dollar::afficher() const
{
	this->Devise::afficher();
	std::cout << " Dollars" << endl;
}

char Banque::Dollar::type_devise()
{
	return 'D';
}


