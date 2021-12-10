#include "MAD.h"
#include "Devise.h"
#include  <iostream>
using namespace std;
using namespace Banque;
Banque::MAD::MAD(double v) :Devise(v)
{
}

void Banque::MAD::convert(char type)
{
	if (type == 'D')
	{
		this->Devise::operator*(new MAD(0.11));
	}
	if (type == 'E')
	{
		this->Devise::operator*(new MAD(0.095));
	}


}

void Banque::MAD::afficher() const
{
	this->Devise::afficher();
	std::cout << " MAD" << endl;
}

char Banque::MAD::type_devise()
{
	return 'M';
}
