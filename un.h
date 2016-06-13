#ifndef UN_H
#define UN_H
#include<QObject>

class Un : public QObject
{
    Q_OBJECT
public:


    Un(int taille, int position);
    //Un(Un *fils);
    Un(Un *fils, bool dernier);
    void setPosition(int posit);
    void setFin(int fi);
    int getFin();
    int getPosition();
    int getId();
    void allerADroite();



public slots:
    void decalerADroite();

signals:
    void fini();

private:
    int fin;
    int position;
    Un *fils;
    int id;
    bool dernier;

};

#endif // UN_H
