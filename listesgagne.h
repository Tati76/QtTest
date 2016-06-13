#ifndef LISTESGAGNE_H
#define LISTESGAGNE_H
#include "un.h"
#include <QVector>

// test git

class ListesGagne : public QObject
{
    Q_OBJECT
public:
    ListesGagne();
    ListesGagne(int taille, int nbDeUns);
    int getTaille();
    int getNbDeUns();
    void setTaille(int taille);
    void setNbDeUns(int nbDeUns);
    QVector<QString> genererListes();
    void remettreAZero();
public slots:
    void finirLaBoucle();
signals:

private:
    int taille; // n
    int nbDeUns; // k   avec k parmi n
    QVector<Un*> tableauUns; // pointeur vers les uns du tableau
    bool finirBoucle;
};

#endif // LISTESGAGNE_H
