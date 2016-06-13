#include "listesgagne.h"
#include <QDebug>

ListesGagne::ListesGagne() : taille(0), nbDeUns(0),finirBoucle(true), tableauUns(0)
{

}

ListesGagne::ListesGagne(int taille, int nbDeUns) : taille(taille), nbDeUns(nbDeUns), finirBoucle(true)
{

    // Premier
    tableauUns.append(new Un(taille,nbDeUns-1));

    // Ensuite
    for (int i(1); i<nbDeUns-1 ; i++)
    {
        tableauUns.append(new Un(tableauUns.last(),false));
    }
    // Dernier
    tableauUns.append(new Un(tableauUns.last(),true));

    QObject::connect(tableauUns.last(),SIGNAL(fini()),this,SLOT(finirLaBoucle()));
}


int ListesGagne::getTaille()
{
    return this->taille;
}

int ListesGagne::getNbDeUns()
{
    return this->nbDeUns;

}

void ListesGagne::setTaille(int taille)
{
    this->taille = taille;
}

void ListesGagne::setNbDeUns(int nbDeUns)
{
    this->nbDeUns = nbDeUns;
}

QVector<QString > ListesGagne::genererListes()
{
    this->finirBoucle = false; // on veut commencer la boucle
    //creation du Vector pour afficher provisoirement monitoring
    QVector<int> tableau(this->taille,0);
    QString reponse("");
    QVector<QString> reponses(0);
    while(this->finirBoucle == false)
    {
        //pour afficher le tableau
            for (int i(0);i<this->nbDeUns; i++)
            {
                tableau[tableauUns[i]->getPosition()] = 1;
            }
            for (int i(0);i<tableau.size(); i++)
            {
                reponse.append(QString::number(tableau[i])) ;
            }

            reponses.append(reponse);

            //remettre que des 0 dans le tableau
            for (int i(0);i<tableau.size(); i++)
            {
                tableau[i] = 0;
            }
            reponse = "";
        //fini d'afficher

        this->tableauUns.first()->allerADroite(); // On commande tout grace au premier Un qui dirige
    }
    this->remettreAZero();
    return reponses;
}

void ListesGagne::finirLaBoucle()
{
    finirBoucle = true;
}

void ListesGagne::remettreAZero()
{
    tableauUns.clear();

    // Premier
    tableauUns.append(new Un(taille,nbDeUns-1));

    // Ensuite
    for (int i(1); i<nbDeUns-1 ; i++)
    {
        tableauUns.append(new Un(tableauUns.last(),false));
    }
    // Dernier
    tableauUns.append(new Un(tableauUns.last(),true));

}
