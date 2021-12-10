#include "Euro.h"
#include "MAD.h"
#include "Dollar.h"
#include  <iostream>
using namespace std;
using namespace Banque;

Banque::Euro::Euro(double v) :Devise(v)
{
}

void Banque::Euro::convert(char type)
{
	if (type == 'M')
	{
		this->Devise::operator*(new Euro(10.48));
	}
	if (type == 'D')
	{
		this->Devise::operator*(new Euro(1.13));
	}
}

void Banque::Euro::afficher() const
{
	this->Devise::afficher();
	std::cout << "Euro" << endl;
}

char Banque::Euro::type_devise()
{
	return 'E';
}
