#pragma once
#include "Compte.h"
namespace Banque
{
    class CompteCourant : public Compte
    {
    private:
        Devise* decouvert;
    public:
        CompteCourant(Client* c, Devise* m, Devise* decouvert);
        virtual void crediter(Devise* M);
        virtual bool debiter(Devise* M);
        void consulter() const override;
    };
};

