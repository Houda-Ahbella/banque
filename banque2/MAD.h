#pragma once
#include "Devise.h"
namespace Banque {

	class MAD : public Devise
	{

	public:
		MAD(double v);
		virtual void convert(char type);
		virtual void afficher() const ;
		char type_devise() override;

	};

}