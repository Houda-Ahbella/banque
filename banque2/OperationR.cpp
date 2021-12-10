#include "OperationR.h"

Banque::OperationR::OperationR(Date* d, Devise* montant)
	: Operation(d, montant)
{
}

void Banque::OperationR::afficher()
{
	std::cout << " - ";
	this->Operation::afficher();
}




