#-------------------------------------------------
#
# Project created by QtCreator 2015-11-07T00:34:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtOrbit
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    orbitview.cpp \
    satellite.cpp \
    satellitelist.cpp \
    planet.cpp

HEADERS  += mainwindow.h \
    orbitview.h \
    satellite.h \
    satellitelist.h \
    constants.h \
    planet.h

FORMS    += mainwindow.ui
