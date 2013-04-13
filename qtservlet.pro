#-------------------------------------------------
#
# Project created by QtCreator 2013-04-11T23:41:34
#
#-------------------------------------------------

QT       += network

QT       -= gui

# C++11
QMAKE_CXXFLAGS = -std=c++11 -stdlib=libc++

TARGET = qtservlet
TEMPLATE = lib

DEFINES += QTSERVLET_LIBRARY

SOURCES += qservlet.cpp \
    servletresponse.cpp \
    qhttpservletserver.cpp \
    servlets/testservlet.cpp \
    servlets/error404servlet.cpp \
    servlets/randomnumberservlet.cpp

HEADERS += qservlet.h\
        qtservlet_global.h \
    servletresponse.h \
    qhttpservletserver.h \
    servlets/testservlet.h \
    servlets/error404servlet.h \
    servlets/randomnumberservlet.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
