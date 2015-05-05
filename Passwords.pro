#-------------------------------------------------
#
# Project created by QtCreator 2015-05-03T13:09:34
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Passwords
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    model.cpp

HEADERS  += mainwindow.h \
    login.h

FORMS    += mainwindow.ui \
    login.ui
