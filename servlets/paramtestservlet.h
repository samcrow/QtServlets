#ifndef PARAMTESTSERVLET_H
#define PARAMTESTSERVLET_H

#include "../qservlet.h"

class ParamTestServlet : public QServlet
{
    Q_OBJECT
public:
    explicit ParamTestServlet(QString specifiedPath = QString(), QObject *parent = 0);
    
    void processRequest(ParamList &params, ServletResponse &response);
    
signals:
    
public slots:
    
};

#endif // PARAMTESTSERVLET_H
