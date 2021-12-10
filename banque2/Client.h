#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "GC.h"
using namespace std;
namespace Banque {
	class Compte;
	class Client
	{
		// attributs
	private:
		string nom;
		string prenom;
		string adresse;
		vector <Compte*> list_compte;
	 

	public:
		Client(string nom, string prenom, string adresse);
		void Afficher()const;
		void addCompte(Compte* c);
		GC* ref;

	};
};
