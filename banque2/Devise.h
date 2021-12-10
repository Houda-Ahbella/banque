#pragma once
namespace Banque 
{
	class Devise
	{
	private:
		double valeur;
		
	public:
		Devise(double val);
		Devise(Devise& D);
		void operator+(const Devise& M);
		void operator-(const Devise& M);
		void operator*(Devise* M);
		
		virtual bool operator<=(const Devise& M)const ;
		virtual bool operator>=(const Devise& M) const ;
		virtual void convert(char type) = 0;
		virtual char type_devise() = 0;
		virtual void afficher() const;
	};
}

