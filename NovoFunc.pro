#-------------------------------------------------
#
# Project created by QtCreator 2016-09-01T16:00:10
#
#-------------------------------------------------

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NovoFunc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    documentos.cpp \
    cep.cpp \
    manipuladorxml.cpp

HEADERS  += mainwindow.h \
    documentos.h \
    cep.h \
    manipuladorxml.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

