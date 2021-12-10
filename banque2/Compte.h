#pragma once
#include <vector>
#include"Client.h"
#include "MAD.h"
#include "Dollar.h"
#include "Euro.h"
#include "Operations.h"

namespace Banque {
	class Compte
	{
		
	public:
		Compte(Client* titulaire, Devise* D); 
		Compte(const Compte&);
		~Compte();
		virtual void crediter(Devise* M);
		virtual bool debiter(Devise* M);
		bool verser(Devise* M, Compte& C);
		virtual void consulter() const = 0;
		
	protected: bool checkSolde(Devise* M, Devise* dec);
			 Devise& pourcetage(Devise*);
			
	private:
		vector <Operation*> historique;
		const int numcompte;
		static int count;
		Client* titulaire;
		Devise* solde;
		static MAD* plafond;
		
	};
};