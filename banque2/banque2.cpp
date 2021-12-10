// banque2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include "MAD.h"
#include "Dollar.h"
#include "Euro.h"
#include "Client.h"
#include "Compte.h"
#include "CompteEpargne.h"
#include "CompteCourant.h"
#include "ComptePayant.h"

using namespace std;
using namespace Banque;

int main()
{
   // ---------Creation du client 
    Client*C1 = new Client("C1","C1", "Adress1");
    Client* C2 = new Client("C2", "C2", "Adress2");

    // -------creation de compte courant
            // creation de ses devises
    MAD D(1000);
    MAD DD(20);
    Dollar DD1(100);
    Dollar DD2(10);
    CompteCourant Cour1(C1,&D,&DD);
    C1->addCompte(&Cour1);
    if (Cour1.debiter(&DD1)) cout << "retrait  avec succes\n";
    else cout << "retrait echouee \n";
    Cour1.crediter(&DD2);
    Cour1.consulter();
    // -------creation de compte Epargne
           // creation de ses devises

    MAD C(2000);
    Dollar CC1(100);
    Euro CC2(10);
    CompteEpargne Eparg1(C2,&C,10.0);
    if (Eparg1.debiter(&CC1)) cout << "retrait  avec succes\n";
    else cout << "retrait echouee \n";
    Eparg1.crediter(&CC2);
    Eparg1.consulter();

    // -------creation de compte Payant
           // creation de ses devises


    MAD A(3000);
    Dollar AA1(100);
    Euro AA2(10);
    ComptePayant Payant1(C1,&A);
    C1->addCompte(&Payant1);
    if (Payant1.debiter(&AA1)) cout << "retrait  avec succes\n";
    else cout << "retrait echouee \n";
    Payant1.crediter(&AA2);
    Payant1.consulter();
    

    // affichage du Client avec toutes les informations
    C1->Afficher();
   
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
