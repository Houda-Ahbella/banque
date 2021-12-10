#pragma once
#include "Operations.h"
namespace Banque {
    class OperationA : public Operation
    {
    public:

        OperationA(Date* d, Devise* montant);
        void afficher() override;
    private:
    };
};
