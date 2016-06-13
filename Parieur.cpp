#include "Pari.h"
#include "Parieur.h"
#include <math.h>
#include <QVector>

Parieur::Parieur() : bankroll(0), reussite(0), utiliserReussite(0), pourcentageAParier(10), listeDeParis()
{

}
Parieur::Parieur(double bank) : bankroll(floor(bank*100)*0.01), reussite(0), utiliserReussite(0), pourcentageAParier(10), listeDeParis()
{

}

Parieur::Parieur(double bank,double reussit, double utiliserReusit, double pourcentapar) : bankroll(floor(bank*100)*0.01), reussite(reussit), utiliserReussite(utiliserReusit), pourcentageAParier(pourcentapar),listeDeParis()
{

}

Parieur::~Parieur()
{

}

double Parieur::getReussite()
{
    return this->reussite;
}

double Parieur::getUtiliserReussite()
{
    return this->utiliserReussite;
}

double Parieur::getBankroll()
{
    return this->bankroll;
}

void Parieur::setReussite(double toSet)
{
    this->reussite = toSet;
}

void Parieur::setUtiliserReussite(double toSet)
{
    this->utiliserReussite = toSet;
}

void Parieur::setBankroll(double toSet)
{
    this->bankroll = toSet;
}

void Parieur::addReussite(double toAdd)
{
    this->bankroll += toAdd;
}

void Parieur::addBankroll(double toAdd)
{
    this->bankroll += toAdd;
}

void Parieur::parier(Pari *par)
{
    if (par->getReussi() == true) // pari reussi
    {
        bankroll += floor(pourcentageAParier*bankroll*(par->getCote()-1))*0.01;
    }

    else // pari râté
    {
        bankroll -= floor(pourcentageAParier*bankroll)*0.01;
    }
}

void Parieur::parier(QVector<bool> listeReus, QVector<double> listeCote)
{
    if (listeReus.size() == listeCote.size()) // si pas le meme nombre de pari dans les 2 listes on ne commence pas
    {
        for(int i(0); i<listeReus.size() ; i++) // on boucle pour faire tous les paris
        {
            this->listeDeParis.append(new Pari(listeCote[i],listeReus[i]));
            this->parier(this->listeDeParis.last()); // on fait le pari
        }
    }
    else
    {
    // ////ERREUR
    }
}


void Parieur::setPourcentageAParier(double toSet)
{
    this->pourcentageAParier = toSet;
}
