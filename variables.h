#ifndef VARIABLES_H
#define VARIABLES_H
#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class Variables;
}

class Variables : public QWidget
{
    Q_OBJECT

public:
    explicit Variables(QWidget *parent = 0);
    explicit Variables(MainWindow *parent);
    ~Variables();

public slots:
    void changerVariables();
signals:

private:
    Ui::Variables *ui;
    MainWindow *fenetre;
};

#endif // VARIABLES_H
