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
    testservlet.cpp \
    error404servlet.cpp

HEADERS += qservlet.h\
        qtservlet_global.h \
    servletresponse.h \
    qhttpservletserver.h \
    testservlet.h \
    error404servlet.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
