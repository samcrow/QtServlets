#include "qservlet.h"


QServlet::QServlet(QString specifiedPath, QObject *parent) :
    QObject(parent),
    specifiedPath(specifiedPath)
{
}

bool QServlet::matchesPath(QString &path) {
    if(!specifiedPath.isEmpty()) {
        return path == specifiedPath;
    }
    return false;
}
