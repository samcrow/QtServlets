#include "randomnumberservlet.h"
#include <QDateTime>

RandomNumberServlet::RandomNumberServlet(QString specifiedPath, QObject *parent) :
    QServlet(specifiedPath, parent)
{
    qsrand(QDateTime::currentMSecsSinceEpoch());
}

void RandomNumberServlet::processRequest(ParamList &/*params*/, ServletResponse &response) {
    response.setContentType("text/plain");
    
    response << QString::number(qrand());
}
