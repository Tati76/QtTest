#include "un.h"

Un::Un(int taille, int position) : fin(taille-1), position(position), fils(), id(0), dernier(false)
{

}


/*Un::Un(Un *fils) : fin(fils->getFin()-1), position(fils->getPosition()-1), fils(fils), id(fils->getId() + 1), dernier(false) // attention poiteur et argument de la methode peut etre confusion
{
    QObject::connect(fils,fils->fini(),this,decalerADroite());

}*/

Un::Un(Un *fils, bool dernier) : fin(fils->getFin()-1), position(fils->getPosition()-1), fils(fils), id(fils->getId() + 1), dernier(dernier) // attention poiteur et argument de la methode peut etre confusion
{
    QObject::connect(fils,SIGNAL(fini()),this,SLOT(decalerADroite()));
}


void Un::setFin(int fi)
{
    this->fin = fi;
}

void Un::setPosition(int posit)
{
    this->position = posit;
}

void Un::allerADroite() // methode
{
    this->decalerADroite();
}

void Un::decalerADroite() //slot
{
    if (this->position == this->fin)
    {
        emit this->fini();
    }
    else
    {
        this->position += 1;
    }

    // On regarde la position du fils
    if(fils != 0)
    {
        if (this->fils->getPosition() == this->fils->getFin())
        {
            this->fils->setPosition(position + 1);
        }
    }
}
// slot fini()

int Un::getFin()
{
    return this->fin;
}

int Un::getPosition()
{
    return position;
}

int Un::getId()
{
    return this->id;
}
