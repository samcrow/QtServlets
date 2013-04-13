#ifndef RANDOMNUMBERSERVLET_H
#define RANDOMNUMBERSERVLET_H

#include "../qservlet.h"

class RandomNumberServlet : public QServlet
{
    Q_OBJECT
public:
    explicit RandomNumberServlet(QString specifiedPath = QString(), QObject *parent = 0);
    
    void processRequest(ParamList &params, ServletResponse &response);
    
signals:
    
public slots:
    
};

#endif // RANDOMNUMBERSERVLET_H
