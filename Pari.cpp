#include "Pari.h"

Pari::Pari() : cote(0), reussi(0)
{

}

Pari::Pari(double cot) : cote(cot), reussi(0)
{

}

Pari::Pari(double cot, bool reuss) : cote(cot), reussi(reuss)
{

}

Pari::~Pari()
{

}

double Pari::getCote()
{
    return this->cote;
}

void Pari::setCote(double toSet)
{
    this->cote = toSet;
}

bool Pari::getReussi()
{
    return this->reussi;
}

void Pari::setReussi(bool toSet)
{
    this->reussi = toSet;
}
