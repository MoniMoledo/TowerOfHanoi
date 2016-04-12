#-------------------------------------------------
#
# Project created by QtCreator 2016-04-04T10:52:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerofHanoi
TEMPLATE = app


SOURCES += main.cpp\
        hanoi.cpp \
    pole.cpp \
    disk.cpp \
    move.cpp

HEADERS  += hanoi.h \
    pole.h \
    disk.h \
    move.h

FORMS    += hanoi.ui
