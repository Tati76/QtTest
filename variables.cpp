#include "variables.h"
#include "ui_variables.h"

Variables::Variables(MainWindow *parent) :
    QWidget(0),
    ui(new Ui::Variables), fenetre(parent)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(changerVariables()));

}

Variables::~Variables()
{
    delete ui;
}

void Variables::changerVariables()
{
    double o = ui->lineEdit->text().toDouble();
    if (ui->lineEdit->text() != "")
    {
        fenetre->setBankrollParieur(ui->lineEdit->text().toDouble());
    }
    if (ui->lineEdit_2->text() != "")
    {
        fenetre->setPourcentageAParierParieur(ui->lineEdit_2->text().toDouble());
    }
    if (ui->lineEdit_3->text() != "")
    {
        fenetre->setReussiteParieur(ui->lineEdit_3->text().toDouble());
    }
    fenetre->setBankrollUpToDate();
}
