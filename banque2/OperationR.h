#pragma once
#include "Operations.h"
namespace Banque
{
    class OperationR : public Operation
    {
    public:
        OperationR(Date* d, Devise* montant);
        void afficher() override;
    private:

    };
}

