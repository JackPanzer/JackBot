#-------------------------------------------------
#
# Project created by QtCreator 2013-07-18T14:37:19
#
#-------------------------------------------------

QT       += core gui\
        network

TARGET = JackPanzer-JackBot
TEMPLATE = app


SOURCES += main.cpp\
        commandwindow.cpp \
    connectionsocket.cpp \
    commandblock.cpp

HEADERS  += commandwindow.h \
    connectionsocket.h \
    commandblock.h

FORMS    += commandwindow.ui
