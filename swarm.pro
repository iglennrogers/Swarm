#-------------------------------------------------
#
# Project created by QtCreator 2014-05-20T16:17:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = swarm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    firefly.cpp \
    lightblock.cpp \
    gameworld.cpp \
    gravitationalobject.cpp \
    repulsorblock.cpp \
    attractorblock.cpp

HEADERS  += mainwindow.h \
    firefly.h \
    lightblock.h \
    gameworld.h \
    gravitationalobject.h \
    repulsorblock.h \
    attractorblock.h

FORMS    += mainwindow.ui
