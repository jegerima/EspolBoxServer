#-------------------------------------------------
#
# Project created by QtCreator 2014-06-11T11:10:25
#
#-------------------------------------------------

QT       += core
QT       += network

QT       -= gui

TARGET = EspolBoxServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    espolboxserver.cpp \
    serverthread.cpp

HEADERS += \
    espolboxserver.h \
    serverthread.h
