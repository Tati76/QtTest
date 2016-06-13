#include "mainwindow.h"
#include <QApplication>
#include "Parieur.h"
#include "Pari.h"
#include <QDebug>
#include "un.h"
#include <QVector>
#include "listesgagne.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
