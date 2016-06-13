#ifndef PARI_H
#define PARI_H

class Pari
{

public:
    Pari(); //Constructeur
    Pari(double cot);
    Pari(double cot, bool reuss);
    ~Pari(); //Destructeur
    double getCote();
    void setCote(double toSet);
    bool getReussi();
    void setReussi(bool toSet);

private:
    double cote;
    bool reussi;

};

#endif // PARI_H
