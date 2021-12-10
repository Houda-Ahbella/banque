#pragma once
#include "Compte.h"
namespace Banque {
    class ComptePayant : public Compte
    {
    private:
        static double coutop;
    public:
        ComptePayant(Client* c, Devise* m);
        bool debiter(Devise* M) override;
        void crediter(Devise* M) override;
        void consulter() const override;
    };
};

