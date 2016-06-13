#-------------------------------------------------
#
# Project created by QtCreator 2016-04-27T23:44:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Pari
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    listesgagne.cpp \
    Pari.cpp \
    Parieur.cpp \
    un.cpp \
    variables.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    listesgagne.h \
    Pari.h \
    Parieur.h \
    un.h \
    variables.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    variables.ui
