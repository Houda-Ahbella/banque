#pragma once
#include <iostream>
#include "Date.h"
#include "Devise.h"
using namespace std;
namespace Banque
{
	class Operation
	{
	private:
		static int compteur;
		const int num;
		Date* d;
		Devise* montant;
	public:
		Operation(Date* d, Devise* montant );
		virtual void afficher()=0;
	};
};

