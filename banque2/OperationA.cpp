#include "OperationA.h"

Banque::OperationA::OperationA(Date* d, Devise* montant)
	:Operation(d, montant)
{
}

void Banque::OperationA::afficher()
{
	std::cout << " + ";
	this->Operation::afficher();

}
