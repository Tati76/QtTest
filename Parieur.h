#ifndef PARIEUR_H
#define PARIEUR_H
#include "Pari.h"
#include <QVector>

class Parieur
{

public:
    Parieur();
    Parieur(double bank);
    Parieur(double bank,double reussit, double utiliserReusit,double pourcentapar);
    ~Parieur();
    double getReussite();
    double getUtiliserReussite();
    double getBankroll();
    void setReussite(double toSet);
    void setUtiliserReussite(double toSet);
    void setBankroll(double toSet);
    void setPourcentageAParier(double toSet);
    void addReussite(double toAdd);
    void addBankroll(double toAdd);
    void parier(Pari *par);
    void parier(QVector<bool> listeReus, QVector<double> listeCote);



private:
    double reussite;
    bool utiliserReussite;
    double bankroll;
    double pourcentageAParier; //pourcentage de la bankroll à parier
    QVector<Pari*> listeDeParis;


};

#endif // PARIEUR_H
