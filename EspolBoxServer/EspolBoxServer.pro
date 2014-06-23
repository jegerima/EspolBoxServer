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
    serverthread.cpp \
    file.cpp \
    libs.cpp \
    textparser.cpp \
    serialfile.cpp \
    ebfile.cpp

HEADERS += \
    espolboxserver.h \
    serverthread.h \
    file.h \
    libs.h \
    textparser.h \
    serialfile.h \
    ebfile.h
