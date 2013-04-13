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
    servlets/randomnumberservlet.cpp \
    servlets/paramtestservlet.cpp \
    pages/segments/htmlheader.cpp \
    pages/segments/htmlfooter.cpp \
    pages/tags/htmltag.cpp \
    pages/tags/metatag.cpp \
    pages/tags/scripttag.cpp \
    pages/tags/parenthtmltag.cpp \
    pages/htmlpage.cpp \
    pages/tags/headhtmltag.cpp \
    pages/tags/bodyhtmltag.cpp \
    pages/tags/titlehtmltag.cpp \
    pages/tags/metacharsethtmltag.cpp \
    pages/tags/textnode.cpp

HEADERS += qservlet.h\
        qtservlet_global.h \
    servletresponse.h \
    qhttpservletserver.h \
    servlets/testservlet.h \
    servlets/error404servlet.h \
    servlets/randomnumberservlet.h \
    servlets/paramtestservlet.h \
    pages/segments/htmlheader.h \
    pages/segments/htmlfooter.h \
    pages/htmldoctypes.h \
    pages/tags/htmltag.h \
    pages/tags/metatag.h \
    pages/tags/scripttag.h \
    pages/tags/parenthtmltag.h \
    pages/htmlpage.h \
    pages/tags/headhtmltag.h \
    pages/tags/bodyhtmltag.h \
    pages/tags/titlehtmltag.h \
    pages/tags/metacharsethtmltag.h \
    pages/tags/textnode.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
