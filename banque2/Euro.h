#pragma once
#include "Devise.h"
namespace Banque 
{
    class Euro :
        public Devise
    {
    public:
        Euro(double v);
        void convert(char type) override;
        void afficher() const override;
        char type_devise() override;
    };
}
