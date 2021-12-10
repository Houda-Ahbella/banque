#pragma once
#include "Compte.h"
namespace Banque
{
    class CompteEpargne :
        public Compte
    {
	private:
		double tauxI;
	public:
		CompteEpargne(Client* c, Devise* m, double TI);
		void calculInteret();
		void consulter() const override;
    };

};


