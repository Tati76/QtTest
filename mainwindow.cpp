#include "mainwindow.h"
#include "variables.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->parieur = new Parieur(100.0,100.0,1.0,45.0);
    liste = new ListesGagne(8,2);
    QObject::connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(goToItem()));
    QObject::connect(this,SIGNAL(itemRecherche(const QListWidgetItem*)),ui->listWidget,SLOT(scrollToItem(const QListWidgetItem*)));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(ecrireListe()));
    QObject::connect(ui->actionVariables,SIGNAL(triggered()),this,SLOT(lancerFenetreVariables()));




    this->bankroll = 100;

    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->widgetPlot->addGraph();
    ui->widgetPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->widgetPlot->xAxis->setLabel("x");
    ui->widgetPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->widgetPlot->xAxis->setRange(-6, 1);
    ui->widgetPlot->yAxis->setRange(0, 1);
    ui->widgetPlot->replot();





qDebug() << "bankroll : " << parieur->getBankroll();







}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setListeGagne(ListesGagne list)
{
    this->liste = &list;
}

void MainWindow::ecrireListe()
{
    double resultatAEcrire=0;
    ListesGagne *listeProvisoire = new ListesGagne(ui->lineEdit_n->text().toInt(),ui->lineEdit_k->text().toInt());
    ui->listWidget->clear();
    QVector<QString> *resultat = new QVector<QString>(listeProvisoire->genererListes());
    //resultat = liste->genererListes();
    /*for (int i(0); i<resultat->size();i++)
    {
        ui->listWidget->addItem((*resultat)[i]);
    }*/
    qDebug() << resultat->size() ; // print le nb de resultats
    double AB = bankrollApresParis(resultat,1.44,100.0);
    delete resultat;
    delete listeProvisoire;
}

void MainWindow::goToItem()
{
    QListWidgetItem *recherche = new QListWidgetItem(ui->lineEdit->text());
    emit itemRecherche(recherche);
}

void MainWindow::lancerFenetreVariables()
{
    Variables *var = new Variables(this);
    var->show();
}

void MainWindow::changerVariables(double bkr, double percent)
{
    this->parieur->setBankroll(bkr);
    this->parieur->setReussite(percent);
}

Parieur MainWindow::getParieur()
{
    return *parieur;
}

void MainWindow::setBankrollUpToDate()
{
    ui->label_Bankroll->setText(QString::number(this->parieur->getBankroll()));
    ui->label_PourcentageParis->setText(QString::number(this->parieur->getReussite()));
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->label_Bankroll->setText(arg1);
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString *stringtemporaire = new QString(item->text());
    QVector<int> *listeResultats = new QVector<int>(0);
    for (int i = 0 ; i < item->text().size() ; i++)
    {
        //qDebug() << stringtemporaire->mid(i,1).toInt();
        listeResultats->append(stringtemporaire->mid(i,1).toInt());
    }
    faireGraph(listeResultats);
    delete listeResultats;
}

void MainWindow::setBankrollParieur(double bk)
{
    this->parieur->setBankroll(bk);

}

void MainWindow::faireGraph(QVector<int> *listeRes)
{
    parieur->setBankroll(100);
    QVector<double> *listeBk = new QVector<double>(0);
    QVector<double> *listeNb = new QVector<double>(0);
    listeBk->append(parieur->getBankroll());
    listeNb->append(0.0);
    for(int i = 1 ; i<=listeRes->size() ; i++)
    {
        parieur->parier(new Pari(1.5,(*listeRes)[i-1]));
        listeBk->append(parieur->getBankroll());
        listeNb->append((double)i);
    }
    qDebug() << "bankroll finale : " << parieur->getBankroll();
    ui->widgetPlot->removeGraph(0);
    //ui->widgetPlot->clearGraphs();
    ui->widgetPlot->addGraph();
    ui->widgetPlot->graph(0)->setData(*listeNb, *listeBk);
    ui->widgetPlot->graph(0)->rescaleAxes();
    qDebug() << "fini de tracer";
    delete listeBk;
    delete listeNb;
}

void MainWindow::setPourcentageAParierParieur(double toSet)
{
    this->parieur->setPourcentageAParier(toSet);
}

void MainWindow::setReussiteParieur(double toSet)
{
    this->parieur->setReussite(toSet);
}

double MainWindow::bankrollApresParis(QVector<QString> *listeResultats, double coteUnique, double bk )
{
    double res = 0;
    double resMin = 0;
    int positionMin = 0;
    int position = 0;
    for (int i=0 ; i<listeResultats->size() ; i++)
    {
        parieur->setBankroll(bk);
        for(int a=0 ; a<(*listeResultats)[i].size() ; a++)
        {
            parieur->parier(new Pari(coteUnique,(*listeResultats)[i][a].digitValue()));
        }
        if (i==0)
        {
            resMin = parieur->getBankroll();
        }
        if(res < parieur->getBankroll())
        {
            res = parieur->getBankroll();
            position = i;
        }
        if(resMin > parieur->getBankroll())
        {
            resMin = parieur->getBankroll();
            positionMin = i;
        }
    }
    qDebug() << "Max : " << res << "   en position : " << position;
    qDebug() << "Min : " << resMin << "   en position : " << positionMin;
    double resultat = parieur->getBankroll();
    parieur->setBankroll(bk);
    return resultat;
}
