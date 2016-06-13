#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Pari.h"
#include "Parieur.h"
#include "un.h"
#include "listesgagne.h"
#include <QListWidgetItem>

#include <QDebug>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setListeGagne(ListesGagne list);
    Parieur getParieur();
    void setBankrollUpToDate();
    void setBankrollParieur(double bk);
    void setPourcentageAParierParieur(double toSet);
    void setReussiteParieur(double toSet);
public slots:
    void goToItem();
    void changerVariables(double bkr, double percent);
    void ecrireListe();
    void lancerFenetreVariables();
    void faireGraph(QVector<int> *listeRes);

signals:
    void itemRecherche(const QListWidgetItem*);
private slots:
    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    ListesGagne *liste;
    Parieur *parieur;
};

#endif // MAINWINDOW_H
